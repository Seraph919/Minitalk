# :white_check_mark: Minitalk
<h2>Grade</h2>

![grade](https://github.com/user-attachments/assets/abd24828-fce9-4642-820d-a1f2987b9fa0)

</div>

## Description  
The Minitalk project from 42 is focused on inter-process communication (IPC) using signals in Unix-based systems.
It’s a project designed to teach you how processes can send and receive messages asynchronously using low-level system calls. 


# Overview
First, the communication relies on the two signals: SIGUSR1 and SIGUSR2; a string (received in input) is sent from the client to the server, after the process is ended the message will be printed from the server, also the client aknowledges the end of the task. First the server must be executed, it will print its PID; then we can run the client giving it two arguments:
    - the server PID
    - the message to send (double quotes for multiple words)

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/c196d29c-f0b3-48d1-8cf2-bb2dafb6f00a" alt="Centered cient"/>
</div>

<div style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/ded59305-9f1f-401d-87a1-17a95b642034" alt="Centered server"/>
</div>

It is possible to send multiple messages in different calls without stopping the server.
# Structure
- **sources/**   -->  source files:
                          - client.c
                          - server.c
                          - client_bonus.c
                          - server_bonus.c

# Execute
- command `make` and `make bonus` creates the two executables: server and client or server_bonus and client_bonus
- The `server` must be executed first, 
- `client` follows with the arguments
- other make commands: `re`, `re bonus`, `clean`, `fclean`
