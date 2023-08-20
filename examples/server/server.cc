#include <iostream>
#include <string>

#include "examples/server/data/web_data.h"
#include "httplib.h"

int main(int argc, char* argv[]) {
  const std::string html = std::string(examples::server::data::index_html());
  const std::string css = std::string(examples::server::data::styles_css());
  const std::string js = std::string(examples::server::data::script_js());

  httplib::Server svr;

  svr.Get("/", [&](const httplib::Request&, httplib::Response& res) {
    res.set_content(html, "text/html");
  });

  svr.Get("/styles.css", [&](const httplib::Request&, httplib::Response& res) {
    res.set_content(css, "text/css");
  });

  svr.Get("/script.js", [&](const httplib::Request&, httplib::Response& res) {
    res.set_content(js, "application/javascript");
  });

  svr.listen("localhost", 8080);

  return 0;
}
