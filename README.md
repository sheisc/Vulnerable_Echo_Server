# Vulnerable_Echo_Server
Vulnerable_Echo_Server: A vulnerable Multi-Process Echo Server and its evil clients.

Overview:

Please see [VulnerableEcho.png]  (https://github.com/sheisc/Vulnerable_Echo_Server/blob/master/VulnerableEcho.png) for what this program does. 

It has been tested on 32-bit Ubuntu 12.04, as a simple example to demonstrate
(1) Buffer Overflow and its exploits
(2) GOT Table overwrite (Suppose it is writable)
(3) Bypassing Stack Canaries and ASLR via information disclosure
(4) Brute-Force guessing.
(5) Format string vulnerbility

Since the calling convention and memory layout are quite different in 64-bit system,
some extra work is needed to use it on systems other than 32-bit Ubuntu 12.04.




