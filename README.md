## Vacancy Train

#### Steps to create the linux image and add it to the SD

- Insert the SD card to your computer.
- Go to the disks application in ubuntu and format the SD (it is not necessary to fill it with zeroes)
- Open a terminal and go to the folder `Documents/Embebidos/yocto/poky-dunfell-23.0.2/`
- Initialize the variables with `source oe-init-build-env rpi2`
- Inside the `rpi2` folder run the following command to construct the image `bitbake rpi-basic-image` (This generates the image, it should last too much the second time you do it).
- Once the image finishes, run `lsblk` and recognize the path of the SD. It could be `/dev/sdb`.
- Run the following commands to copy the image into the SD `cd tmp/deploy/images/raspberrypi2` and `sudo bmaptool copy rpi-basic-image-raspberrypi2.wic.bz2 /dev/sdb`

#### Steps to add the server and GPIO library into the SD

- Clone this repository in your computer.
- Go to the folder where you cloned the repository in the terminal.
- Run this commands to copy the GPIO library into the SD `cd libgpioman-1.0/` and `sudo cp -r usr/* /media/juanignava/root` (verufy your SD location in the computer for this step)
- Then go back to the main folder with `cd ..` and run `sudo cp -r server/ /media/juanignava/root`.

#### Steps to run the server in the raspberry for the first time

- Remove the SD card from the computer and insert it into the Raspberry.
- Connect a monitor, keyboard and Ethernet cable (connected to the client computer) into the Raspberry.
- Connect the Raspberry to the power adapter.
- Wait until the Raspberry loads and asks to login, to continue type `root`
- Verify the internet connection by wirting in the console `ifconfig` if it shows an ip similar or equal to `10.42.0.88` it is connected.
- If there is no connection, look into the settings of the client computer and go to Network -> settings -> ipv4 and ipv6 and check the option that says 'shared to other computers' on both ip.
- Then continue with installing flask and flask-cors packages with `pip install --trusted-host pypi.org --trusted-host files.pythonhosted.org <package_name> -vvv` 
- To confirm all the configuration run the webs server with `cd server` and `python3 app.py`.
- Kill the server with ctrl+C.
- Create a running demon by running the commands (inside `/server`) `cp app-server.service /etc/systemd/system` and then `systemctl start app-server.service`.
- Last step is to enable the service so ir runs when the system boots, for this run `systemctl enable app-service.service`

#### Stepts to run the server for the next times


- Remove the SD card from the computer and insert it into the Raspberry.
- Connect a monitor, keyboard and Ethernet cable (connected to the client computer) into the Raspberry.
- Connect the Raspberry to the power adapter.
- Wait until the Raspberry loads and asks to login, to continue type `root`
- The server must be running at this point.

