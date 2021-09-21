int main(void) {
  // Logging server port number
  INET_Addr server_addr(PORT);

  // Initialize logging server endpoint and
  // register with the Initiation_Dispatcher
  for (;;) {
    Initiation_Dispatcher::instance() -> handle_events();
  }

  return 0;
}
