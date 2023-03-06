### Command Information for `hostname`

The 'hostname' command is used to display or set the hostname of the system. The hostname is a label assigned to a device on a network, used to identify the device among other devices.

To display the current hostname:

```
hostname
```

To set a new hostname:

```
sudo hostname new_hostname
```

Note that changing the hostname will only be temporary and will revert back to the original hostname upon reboot. If you want to permanently change the hostname, you need to modify the appropriate configuration file(s).

Executing command: hostname

Output:

```bash
Matthews-MacBook-Pro.local

```

### Command Information for `env`

The `env` command stands for "environment" and is used to list the environment variables that are currently set in the shell session. These environment variables are specific to the current user and typically include information such as the user's login name, home directory, and system settings.

The `env` command can also be used to run a command with a modified environment. For example, `env VAR=value command` would run the specified `command` with the value of the `VAR` environment variable set to `value`. This can be useful for temporarily modifying the environment without permanently changing system settings.

Executing command: env

Output:

```bash
MANPATH=/opt/local/share/man:/opt/homebrew/share/man::
TERM=xterm-color
SHELL=/bin/zsh
CLICOLOR=1
HOMEBREW_REPOSITORY=/opt/homebrew
TMPDIR=/var/folders/lq/8dq9nc0x3xv1j6hzt_zbrbhh0000gn/T/
LIBRARY_PATH=/usr/local/lib
PYTHONUNBUFFERED=1
SDKROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
MallocNanoZone=0
PYTHONIOENCODING=utf-8
USER=mattraghu
COMMAND_MODE=unix2003
CPATH=/usr/local/include
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.dYM7BV3UvQ/Listeners
__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
JPY_PARENT_PID=32807
PAGER=cat
VSCODE_AMD_ENTRYPOINT=vs/workbench/api/node/extensionHostProcess
ELECTRON_RUN_AS_NODE=1
JUPYTER_PATH=/Users/mattraghu/.vscode/extensions/ms-toolsai.jupyter-2022.6.1201981810/temp/jupyter
PATH=/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
LaunchInstanceID=8423E27D-B923-4125-9D5A-6B9DA6A75CFF
_=/usr/bin/env
__CFBundleIdentifier=com.microsoft.VSCode
PWD=/Users/mattraghu/Documents/Projects/Spring2023/CPE322/Lab2
VSCODE_HANDLES_UNCAUGHT_ERRORS=true
MPLBACKEND=module://matplotlib_inline.backend_inline
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/mattraghu
APPLICATION_INSIGHTS_NO_DIAGNOSTIC_CHANNEL=1
VSCODE_NLS_CONFIG={"locale":"en-us","availableLanguages":{},"_languagePackSupport":true}
HOMEBREW_PREFIX=/opt/homebrew
PYTHONPATH=/Users/mattraghu/.vscode/extensions/ms-toolsai.jupyter-2022.6.1201981810/pythonFiles:/Users/mattraghu/.vscode/extensions/ms-toolsai.jupyter-2022.6.1201981810/pythonFiles/lib/python
LOGNAME=mattraghu
LC_CTYPE=UTF-8
VSCODE_IPC_HOOK=/Users/mattraghu/Library/Application Support/Code/1.69.2-main.sock
VSCODE_CODE_CACHE_PATH=/Users/mattraghu/Library/Application Support/Code/CachedData/3b889b090b5ad5793f524b5d1d39fda662b96a2a
VSCODE_PID=12572
INFOPATH=/opt/homebrew/share/info:
HOMEBREW_CELLAR=/opt/homebrew/Cellar
GIT_PAGER=cat
SECURITYSESSIONID=186b1
VSCODE_CWD=/

```

### Command Information for `ps`

`ps` is a command that shows information about the active user's running processes on the terminal. It provides a dynamic snapshot of the current processes being executed. By default, it shows a list of processes running in the current terminal session, including their process ID (PID), terminal, CPU usage, and memory usage. The command can be used with various options to display more detailed information about the processes. For example, `ps -ef` lists all processes running on the system with detailed information about each process, including the user who started the process, its PID, parent PID (PPID), CPU usage, memory usage, and the time that the process started.

Executing command: ps

Output:

```bash
  PID TTY           TIME CMD
32500 ttys000    0:00.02 /bin/zsh -l
33078 ttys001    0:00.13 -zsh
34315 ttys001    0:00.06 /Library/Frameworks/Python.framework/Versions/3.10/Resources/Python.app/Contents/MacOS/Python

```

### Command Information for `pwd`

`pwd` stands for "print working directory." When you execute this command on the terminal, it will print the full path of the current working directory. It is useful for identifying the location of the current working directory, which can be helpful when navigating through your file system or executing other commands.

Executing command: pwd

Output:

```bash
/Users/mattraghu/Documents/Projects/Spring2023/CPE322/Lab2

```

### Command Information for `git clone https://github.com/kevinwlu/iot.git`

This command clones or downloads a copy of a Git repository located at https://github.com/kevinwlu/iot.git onto your local machine. The repository includes all files, branches, and commits in the repository, allowing you to work with the code on your own machine. Once cloned, you can make changes to the code and push those changes back to the repository. This is a commonly used command for developers who wish to contribute to open source projects, or for team members who need to collaborate on a shared codebase.

Executing command: git clone https://github.com/kevinwlu/iot.git

Output:
This cloned the repository into the current directory. The output is not shown here.

### Command Information for `cd iot`

The "cd" command is used to change the current directory. "iot" is the name of the directory that you want to navigate to. So, the command "cd iot" will change your current directory to the directory named "iot".

Executing command: cd iot

Output:

This command changed the current directory to the directory named "iot". The output is not shown here.

### Command Information for `ls`

The `ls` command stands for "list". It is used to list the files and directories in the current working directory. By default, it lists the files and directories in alphabetical order. You can also use several options with the `ls` command to customize the output. For example, `ls -l` will list files and directories with details like permissions, owner, size, and date modified. `ls -a` will list all files including the hidden files that start with a `.` at the beginning of their names.

Executing command: ls

Output:

```bash
Lab2.ipynb
README.md
demo
iot
output.md
output.txt

```

### Command Information for `cd`

`cd` stands for "change directory" and is used to navigate between different directories (or folders) in the terminal. To use `cd`, you simply type `cd` followed by the name of the directory you want to navigate to. For example, if you want to navigate to a directory called "Documents", you would type:

```
cd Documents
```

You can also use `cd` with relative or absolute paths. Relative paths are specified in relation to the current directory you are in, while absolute paths start from the root directory of your file system. Here are some examples:

```
cd ..         # Move back one directory
cd /home/user # Move to the /home/user directory (absolute path)
cd ~/Desktop  # Move to the Desktop directory in the current user's home directory (relative path using tilde)
```

It's important to note that file and directory names in the terminal are case-sensitive, so "Documents" and "documents" would be treated as different directories.

Executing command: cd

Output:

This command changed the current directory to the home directory. The output is not shown here.

### Command Information for `df`

The `df` (disk free) command is used to report file system disk space usage. When executed, it will display information about the total amount of disk space available, the amount of used and available disk space for each file system, and the filesystem type. This information can be useful for identifying which file systems are approaching capacity and may require additional disk space. By default, `df` displays this information in bytes, but with the use of certain flags, it can also display the information in kilobytes, megabytes, gigabytes, or terabytes.

Executing command: df

Output:

```bash
Filesystem                           512-blocks      Used Available Capacity iused      ifree %iused  Mounted on
/dev/disk3s1s1                        965595304  46526168 477160096     9%  500632 2385800480    0%   /
devfs                                       401       401         0   100%     694          0  100%   /dev
/dev/disk3s6                          965595304   6291512 477160096     2%       3 2385800480    0%   /System/Volumes/VM
/dev/disk3s2                          965595304   1229456 477160096     1%     898 2385800480    0%   /System/Volumes/Preboot
/dev/disk3s4                          965595304   1270224 477160096     1%     246 2385800480    0%   /System/Volumes/Update
/dev/disk1s2                            1024000     12328    982696     2%       1    4913480    0%   /System/Volumes/xarts
/dev/disk1s1                            1024000     15120    982696     2%      34    4913480    0%   /System/Volumes/iSCPreboot
/dev/disk1s3                            1024000      4136    982696     1%      51    4913480    0%   /System/Volumes/Hardware
/dev/disk3s5                          965595304 429509888 477160096    48% 2134462 2385800480    0%   /System/Volumes/Data
map auto_home                                 0         0         0   100%       0          0  100%   /System/Volumes/Data/home
/dev/disk2s1                           10485672   3196408   7250656    31%      58   36253280    0%   /System/Volumes/Update/SFR/mnt1
/dev/disk3s1                          965595304  46526168 477160096     9%  502146 2385800480    0%   /System/Volumes/Update/mnt1
/Applications/Visual Studio Code.app  965595304 422396824 475884552    48% 2084809 2379422760    0%   /private/var/folders/lq/8dq9nc0x3xv1j6hzt_zbrbhh0000gn/T/AppTranslocation/01050430-27BF-4A14-89F1-574B7B134DFA

```

### Command Information for `mkdir demo`

This command creates a new directory called "demo" in the current working directory.

Executing command: mkdir demo

Output:

This command created a new directory called "demo" in the current working directory. The output is not shown here.

### Command Information for `cd demo`

This command is used to change the current working directory to "demo". It is assuming that there is a subdirectory in the current directory named "demo". You can use the command "ls" to list the contents of the current working directory to confirm the existence of "demo" directory.

Executing command: cd demo

Output:

This command changed the current working directory to "demo". The output is not shown here.

### Command Information for `nano file`

The `nano` command opens up a text editor that allows you to create or edit text files right in the terminal window. When you type `nano file` into the terminal, it opens up the `nano` editor and creates or opens a file called `file`. You can then type, insert, or delete text as needed. Once you are done editing your file, you can save your changes and exit nano by pressing `CTRL + X` and then following the prompts to save and/or discard any changes you made.

Executing command: nano file

Output:

This command opened up the `nano` editor and created a new file called `file`. The output is not shown here.

### Command Information for `cat file`

The `cat` command is used to output the contents of a file to the terminal. By typing `cat file`, it will display the contents of the `file` in the terminal screen. If the `file` does not exist in the current working directory, the command will result in an error. If the file is a very large file, the content will scroll down through the terminal screen quickly, and using the `less` command is recommended.

Executing command: cat file

Output:

```bash
Random text that I wrote in the nano editor.
```

### Command Information for `cp file file1`

The `cp` command is short for "copy". In this specific case, `file` is the original file that the user wants to copy, and `file1` is the name of the new copy.

So the command `cp file file1` will create a copy of `file` with the name `file1` in the same directory. This new copy will have the same content as the original `file`. If `file1` already exists, it will be overwritten with the new content.

Executing command: cp file file1

Output:

Copied the contents of `file` to `file1`.

### Command Information for `mv file file2`

The `mv` command is used to move or rename files.

In this specific example, the file named "file" is being renamed to "file2" in the same directory. If a file named "file2" already exists in that directory, it will be overwritten by the renamed "file" file. If "file" is located in a different directory, it will be moved to the current directory and renamed to "file2".

Executing command: mv file file2

Output:

Moved the file named "file" to the current directory and renamed it to "file2".

### Command Information for `rm file2`

The "rm" command is used to remove files or directories in the terminal. In this case, the command "rm file2" will delete the file named "file2" from the current directory. It is important to be careful when using "rm" as it permanently deletes files without sending them to the trash or recycling bin.

Executing command: rm file2

Output:

Removed the file named "file2" from the current directory.

### Command Information for `clear`

The `clear` command is used to clear the terminal window and move the cursor to the top left corner of the terminal window. This command is especially useful when your terminal window is cluttered with text and you want to start fresh without having to close and reopen the window.

Executing command: clear

Output:

Cleared the console
