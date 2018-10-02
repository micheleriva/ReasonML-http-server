module Http = {
  type lib;
  type server;
  type request;
  type response = {. [@bs.meth] "_end": string => unit};
}

[@bs.module]
external http : Http.lib = "http";

[@bs.send.pipe : Http.lib]
external createServer : ((Http.request, Http.response) => unit) => Http.server = "";

[@bs.send.pipe : Http.server]
external listen : int => Http.server = "";

http
  |> createServer((_, res) => res##_end("Hello World"))
  |> listen(5000)