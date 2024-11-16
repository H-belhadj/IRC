/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandParser.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:40:58 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 18:54:05 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include "Message.hpp"
#include <map>

class Client;
class Server;

class CommandParser {
private:
    Server* server;
    std::map<std::string, void (CommandParser::*)(Client&, const Message&)> commandMap;

    // Command handlers
    // void handleNick(Client& client, const Message& msg);
    // void handleUser(Client& client, const Message& msg);
    // void handleJoin(Client& client, const Message& msg);
    // void handlePrivmsg(Client& client, const Message& msg);
    // void handlePart(Client& client, const Message& msg);
    // void handleQuit(Client& client, const Message& msg);
    // void handlePing(Client& client, const Message& msg);
    // void handleMode(Client& client, const Message& msg);
    // void handleKick(Client& client, const Message& msg);
    // void handleTopic(Client& client, const Message& msg);
    // void handleInvite(Client& client, const Message& msg);
    
    // Validation helpers
    bool isValidNickname(const std::string& nick);
    bool isValidChannelName(const std::string& channel);
    bool hasRequiredParams(const Message& msg, size_t required);

public:
    CommandParser(Server* srv);
    ~CommandParser();
    
    void executeCommand(Client& client, const Message& msg);
    bool isRegistered(const Client& client) const;
};

#endif