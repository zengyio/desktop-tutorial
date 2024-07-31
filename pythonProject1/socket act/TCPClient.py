from socket import *
import subprocess

def get_mac_address(ip_address):
    # 先执行 ping 命令，确保目标可达
    subprocess.run(['ping', '-c', '1', ip_address], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # 执行 arp 命令获取 MAC 地址
    arp_result = subprocess.run(['arp', '-a', ip_address], capture_output=True, text=True)
    data = arp_result.stdout
    lines = data.split('\n')
    for line in lines:
        if "192.168.0.63" in line:  # 如果你想匹配其他 IP ，这里修改
            parts = line.split()
            physical_address = parts[1]
            print(physical_address)
    return physical_address

def send_magic_packet(mac_address, ip_address='255.255.255.255', port=9):
    # 构建魔术包数据
    mac_hex = mac_address.replace(':', '').decode('hex')
    magic_packet = b'\xff' * 6 + mac_hex * 16
    # 创建UDP套接字
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    # 发送魔术包
    sock.sendto(magic_packet, (ip_address, port))
    # 关闭套接字
    sock.close()

host_name = "192.168.0.63"
port_num = 1200
hex_mac = get_mac_address(host_name)
print(f"hex_mac before formatting: {hex_mac}")
formatted_mac = ":".join([hex_mac[i:i + 2] for i in range(0, len(hex_mac), 2)])
send_magic_packet(formatted_mac)
with socket(AF_INET, SOCK_STREAM) as clientSocket:
    clientSocket.connect((host_name, port_num))
    while True:
        message = input("enter something: ")
        clientSocket.send(message.encode())

        upperMessage = clientSocket.recv(1024).decode()
        print("the message from the server :" + upperMessage)