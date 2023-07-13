% For Windows OS
if ispc == 1
    mex -O SFun_UDPSocketRecv.c udp_socket.c ws2_32.lib
    mex -O SFun_UDPSocketSend.c udp_socket.c ws2_32.lib
    mex -O SFun_TCPSocketRecv.c tcp_socket.c ws2_32.lib
    mex -O SFun_TCPSocketSend.c tcp_socket.c ws2_32.lib
% For Linux OS
elseif isunix == 1
    mex -O SFun_UDPSocketRecv.c udp_socket.c
    mex -O SFun_UDPSocketSend.c udp_socket.c
    mex -O SFun_TCPSocketRecv.c tcp_socket.c
    mex -O SFun_TCPSocketSend.c tcp_socket.c
end