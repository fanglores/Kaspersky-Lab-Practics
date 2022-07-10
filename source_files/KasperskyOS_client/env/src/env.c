#include <env/env.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("env point 0\n");


    const char* NetVfsArgs[] = {
        "-l", "devfs /dev devfs 0"
    };
    const char* NetVfsEnvs[] = {
        "_VFS_NETWORK_BACKEND=server:VFS1",
        "_VFS_FILESYSTEM_BACKEND=server:VFS1"
    };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("NetVfs", NetVfsArgs, NetVfsEnvs);

    printf("env point 1\n");

    const char* ClientEnvs[] = { "_VFS_NETWORK_BACKEND=client:VFS1", "_VFS_FILESYSTEM_BACKEND=client:VFS1" };
//    ENV_REGISTER_VARS("Client", ClientEnvs);
    ENV_REGISTER_VARS("Server", ClientEnvs);

    envServerRun();

    return EXIT_SUCCESS;
}
