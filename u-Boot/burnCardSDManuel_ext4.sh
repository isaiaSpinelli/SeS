#!/bin/bash
# Spinelli Isaia

echo "---------Initialize 400MiB to 0"
sudo dd if=/dev/zero of=/dev/sdb bs=4k count=100000 status=progress
echo "--sync"
sync

echo "---------First sector: msdos"
sudo parted /dev/sdb mklabel msdos

echo "---------Copy sunxi-spl.bin binaries"
sudo dd if=~/workspace/nano/buildroot/output/images/sunxi-spl.bin of=/dev/sdb bs=512 seek=16 status=progress

echo "---------Copy u-boot"
sudo dd if=~/workspace/nano/buildroot/output/images/u-boot.itb of=/dev/sdb bs=512 seek=80 status=progress


echo "---------1st partition: 64MiB: (163840-32768)*512/1024 = 64MiB " #(sudo fdsik /dev/sdb - interacitf)"
sudo parted /dev/sdb mkpart primary ext4 32768s 163839s


echo "---------2nd partition: 1GiB: 4358144-163840)*512/1024 = 1GiB"
sudo parted /dev/sdb mkpart primary ext4 163840s 4358143s
sudo mkfs.ext4 /dev/sdb1
sudo mkfs.ext4 /dev/sdb2 -L rootfs
echo "--sync"
sync


echo "---------Copy kernel, flattened device tree, boot.scr"
sudo mount /dev/sdb1 /run/media/lmi/
sudo cp ~/workspace/nano/buildroot/output/images/Image /run/media/lmi
sudo cp ~/workspace/nano/buildroot/output/images/nanopi-neo-plus2.dtb /run/media/lmi
sudo cp ~/workspace/nano/buildroot/output/images/boot.scr /run/media/lmi
echo "--sync"
sync

echo "---------Rename 1st partition to BOOT"
sudo umount /dev/sdb1
sudo e2label /dev/sdb1 BOOT
# sudo fatlabel /dev/sdb1 BOOT

echo "---------Copy rootfs"
sudo dd if=~/workspace/nano/buildroot/output/images/rootfs.ext4 of=/dev/sdb2 status=progress


echo "---------Resize and rename 2nd partition to rootfs"
echo "---------Check if the partition must be mounted"
sudo umount /dev/sdb2
sudo e2fsck -f /dev/sdb2
sudo resize2fs /dev/sdb2
sudo e2label /dev/sdb2 rootfs
