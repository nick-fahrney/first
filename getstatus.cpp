#define LIBSSH_STATIC 1
#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

int main()
{
  ssh_session my_ssh_session;
  int rc;
  int port = 22;
  int verbosity = SSH_LOG_PROTOCOL;
  string password;

  my_ssh_session = ssh.new();
  if (my_ssh_session == NULL)
    exit(-1);
  ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "10.13.186.182");
  ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "pi");
  ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);

  rc = ssh_connect(my_ssh_session);
  if (rc != SSH_OK)
  {
    cout << "Error: " << ssh_get_error(my_ssh_session) << endl;
    ssh_free(my_ssh_session);
    exit(-1);
  }
  

  password = "raspberry";
  rc = ssh_userauth_password(my_ssh_session, NULL, password);
  if (rc != SSH_AUTH_SUCCESS)
  {
    cout << "Error authenticating password: " << ssh_get_error(my_ssh_session) << endl;
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    exit(-1);
  }

  
}
