def _embed_data_impl(ctx):
    output_file = ctx.outputs.out
    input_files = ctx.files.srcs
    namespace = input_files[0].dirname.replace("/", "::")
    args = [output_file.path, namespace]
    for file in input_files:
        args.append(file.path)
        args.append(file.basename.replace(".", "_"))
    
    ctx.actions.run(
        inputs = input_files,
        outputs = [output_file],
        executable = ctx.executable._embed_data_tool,
        arguments = args,
    )

    ccinfo = CcInfo(compilation_context = cc_common.create_compilation_context(headers=depset([output_file])))
    return [ccinfo]

embed_data = rule(
    implementation = _embed_data_impl,
    attrs = {
        "srcs": attr.label_list(allow_files=True),
        "_embed_data_tool": attr.label(
            default = Label("@rules_cc_embed_data//cc_embed_data:embed_data"),
            executable = True,
            cfg = "host",
        ),
    },
    outputs = {"out": "%{name}.h"},
)

