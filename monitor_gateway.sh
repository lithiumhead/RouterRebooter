# Send two Ping request packets and 4 seconds timeout
return_value=$(ping -c 2 -W 4 www.google.com)
return_value=$?
# Return code for ping are taken from
# ./OpenWrt-SDK-ar71xx-for-linux-i486-gcc-4.6-linaro_uClibc-0.9.33.2/staging_dir/toolchain-mips_r2_gcc-4.6-linaro_uClibc-0.9.33.2/include/sysexits.h
 
    case $return_value in
        0)  #Ping reply received
            logger "Ping result: ONLINE"
            ;;
        1)  #Ping sent but reply was not received
            logger "Ping result: OFFLINE (Ping reply not received), Rebooting Airtel LTE Gateway..."
            /home/pi/toggle_relays
            ;;
        *)  #Error
            logger "Ping result: OFFLINE (ping return code: $return_value), Rebooting Airtel LTE Gateway..."
            /home/pi/toggle_relays
            ;;
    esac
