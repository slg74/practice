def min_disks(file_sizes, disk_capacity):
    disks = 1
    current_disk_space = disk_capacity

    for size in file_sizes:
        if size > current_disk_space:
            disks += 1
            current_disk_space = disk_capacity
        current_disk_space -= size

    return disks

# Example usage
file_sizes = [100, 200, 300, 400, 500]
disk_capacity = 700

result = min_disks(file_sizes, disk_capacity)
print(f"Minimum number of disks required: {result}")
