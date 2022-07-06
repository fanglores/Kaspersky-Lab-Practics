sudo mount /dev/sdb1 ~/mnt/fat32
sudo cp build/einit/kos-image ~/mnt/fat32/kos-image
sync

sudo umount ~/mnt/fat32
