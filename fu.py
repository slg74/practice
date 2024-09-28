from collections import Counter

def most_frequent_ip(ip_list):
    ip_counts = Counter(ip_list)
    return ip_counts.most_common(1)[0][0]

# Example usage
ip_addresses = ["192.168.1.1", "10.0.0.1", "192.168.1.1", "172.16.0.1", "10.0.0.1", "192.168.1.1"]
most_frequent = most_frequent_ip(ip_addresses)
print(f"Most frequent IP: {most_frequent}")