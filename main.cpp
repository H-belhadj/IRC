#include "server.hpp"
#include "client.hpp"
#include "Parser.hpp"




int main()
{
	// Server ser;
	// std::cout<<YEL<<"-------------> 			SERVER			<-------------"<<WHI<<std::endl;
	// try{
	// 	signal(SIGINT, Server::SignalHandler); //-> catch the signal (ctrl + c)
	// 	signal(SIGQUIT, Server::SignalHandler); //-> catch the signal (ctrl + \)
	// 	ser.ServerInit(); //-> initialize the server
	// }
	// catch(const std::exception& e){
	// 	ser.closeFDS(); //-> close the file descriptors
	// 	std::cerr << e.what() << std::endl;
	// }
	//  std::cout<<BLUE<<"------------->        Server  Closed        <------------- "<<BLUE<<std::endl;
	Message msg = Parser::parseMessage("dgajksdgajksd\r\n");
	msg.print();
}	



//run as client   localhost : 127.0.0.1  port : 4444 