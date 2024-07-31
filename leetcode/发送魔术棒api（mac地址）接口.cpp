#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib") 
#include <afx.h>

using namespace::std;
bool api_computer_start(CString strMac)
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(1, 1), &wsa) != 0)
		return false;

	strMac.MakeUpper();
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;

	BOOL bBroadCast = TRUE;
	USES_CONVERSION;
	const char* szTemp = NULL;
	addrSrv.sin_port = htons(9090);
	setsockopt(sockClient, SOL_SOCKET, SO_BROADCAST, (const char*)&bBroadCast, sizeof(BOOL));
	addrSrv.sin_addr.s_addr = htonl(INADDR_BROADCAST);

	CStringArray ar;
	splitstring(strMac, ar, _T("-"));

	//Magic Packet (魔术包)6个FF是数据的开始,紧跟着16次MAC地址就可以了
	LPBYTE mac = new BYTE[6];
	for (int i = 0; i < 6; i++)
	{
		int nValue = 0;
		swscanf_s(ar[i], _T("%x"), &nValue);
		mac[i] = (BYTE)nValue;
	}

	int nSendSize = 17 * 6;
	LPBYTE buf = new BYTE[nSendSize];
	for (int i = 0; i < 6; i++)
		buf[i] = 0xFF;
	for (int i = 1; i <= 16; i++)
		for (int j = 0; j < 6; j++)
			buf[i * 6 + j] = mac[j];

	delete mac;
	int nReturn = sendto(sockClient, (char *)buf, nSendSize, 0, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	delete buf;
	return nSendSize == nReturn;
}
int main(){
	CString macAddresses[] = { "00-11-22-33-44-55", "11-22-33-44-55-66" };
for (const auto& mac : macAddresses)
{
    if (api_computer_start(mac))
    {
        std::cout << "成功启动计算机: " << mac << std::endl;
    }
    else
    {
        std::cout << "启动计算机 " << mac << " 失败" << std::endl;
    }
}
return 0; 
} 
#ffffffffffff00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae00e04c09faae
