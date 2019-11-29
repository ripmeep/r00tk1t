# rootkit
A simple netcat rootkit for Linux
Written in C

This specific rootkit spawns a netcat process at a kernel level attempting to connect to the chosen listener IP as root

____________________________
# Rootkit
A rootkit is a system level piece of malware which lies underneath the foundation of the operating system, running code with full permissions either on bootup or via a logic bomb.
____________________________
# How to use

_Compile_

    $ make clean
    $ make
    
_Deploy_

    $ insmod r00tk1t.ko
    $ dmesg              # To view kernel logs
        ......
        ......
        [ 1234.1234] R00TK1T START

_Stop_

    $ rmmod r00tk1t
        ......
        ......
        [ 1234.1234] R00TK1T STOP
