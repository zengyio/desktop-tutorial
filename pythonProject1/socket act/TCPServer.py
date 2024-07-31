from socket import *
with socket(AF_INET, SOCK_STREAM) as s:
    s.bind((gethostname(),1200))
    s.listen(2)
    print ("the server is ready to accept information....")

    c,address = s.accept()
    with c:
        print (address,"the client connected.")

        while True:
            data = c.recv(1024)
            if not data:
                break
            c.sendall(data)