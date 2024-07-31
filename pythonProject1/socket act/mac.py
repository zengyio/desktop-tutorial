import subprocess

def get_mac_address(ip_address):
    # 先执行 ping 命令，确保目标可达
    subprocess.run(['ping', '-c', '1', ip_address], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # 执行 arp 命令获取 MAC 地址
    arp_result = subprocess.run(['arp', '-a', ip_address], capture_output=True, text=True)
    data = arp_result.stdout
    lines = data.split('\n')
    physical_address = None
    for line in lines:
        if "192.168.0.63" in line:  # 如果你想匹配其他 IP ，这里修改
            parts = line.split()
            physical_address = parts[1]
            print(physical_address)
    return physical_address

# 测试
ip = "192.168.0.63"  # 替换为你要获取 MAC 地址的 IP
mac = get_mac_address(ip)

if mac:
    print(f"MAC 地址为: {mac}")
else:
    print("未获取到 MAC 地址")