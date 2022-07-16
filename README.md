# Kaspersky Hackaton 2022
#### Moscow Aviation Institute featuring Kaspersky Laboratory hackaton.  Task: create robot platform under the Kaspersky Operating System (KasperskyOS), server under the Linux OS. Server is reading image stream from camera, generating commands for robot, sends them via TCP protocol. Server have to detect color marks and lead robot on route, followed all marks.  
  
#### Quick Access
[Server folder](source_files/linux_server) - server implementation  
[Client folder](source_files/KasperskyOS_client) - client implementation  
  
  
### Repository structure
    .  
    ├── source_files/                       # general folder for the project  
    |    ├── linux_server/                  # server folder  
    |    |    ├── main.py                   # main python script  
    |    |    ├── sockets_module.py         # module, what implements TCP part  
    |    |    ├── recognition_module.py     # module, what implements OpenCV part  
    |    |    ├── mask_structure.py         # class describing data structure for marks  
    |    |    ├── calibration_script.py     # script for calibrating masks  
    |    |    └── README.md                 # to-do list  
    |    |  
    |    └── KasperskyOS_client/            # client folder  
    |         ├── []  
    |         └── []  
    |  
    ├── .gitignore  
    ├── LICENSE  
    └── README.md                           # you are here
  
  
  
© fanglores, Moscow Aviation Institute feat. Kaspersky Lab  
Moscow, 2022
