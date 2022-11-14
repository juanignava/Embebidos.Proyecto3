## GPIO Library

The library GPIO was generated with autotools. To install the library in the raspberry you have to follow this steps:

- open a terminal in the libgpioman-1.0 folder
- insert the SD card of the GPIO in the computer
- write `lsblk` to see the disks connected to the computer in the terminal and locate the SD, its location usualy is `/dev/sdb`.
- Write the following command `sudo cp -R usr/* /dev/sdb/` (WARNING: if the SD partition is no `/dev/sdb` then change this command).
- Check is the files have been correctly copied in the SD files.