/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandParser.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:41:09 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 18:54:40 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CommandParser.hpp"
#include "server.hpp"
#include "client.hpp"
#include <algorithm>

CommandParser::CommandParser(Server* srv) : server(srv) {
    // Initialize command map
    // commandMap["NICK"] = &CommandParser::handleNick;
    // commandMap["USER"] = &CommandParser::handleUser;
    // commandMap["JOIN"] = &CommandParser::handleJoin;
    // commandMap["PRIVMSG"] = &CommandParser::handlePrivmsg;
    // commandMap["PART"] = &CommandParser::handlePart;
    // commandMap["QUIT"] = &CommandParser::handleQuit;
    // commandMap["PING"] = &CommandParser::handlePing;
    // commandMap["MODE"] = &CommandParser::handleMode;
    // commandMap["KICK"] = &CommandParser::handleKick;
    // commandMap["TOPIC"] = &CommandParser::handleTopic;
    // commandMap["INVITE"] = &CommandParser::handleInvite;
}

void CommandParser::executeCommand(Client& client, const Message& msg) {
    std::string command = msg.getCommand();
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    // Check if command exists
    if (commandMap.find(command) != commandMap.end()) {
        // Check if client needs to be registered for this command
        if ((command != "NICK" && command != "USER" && command != "QUIT" && command != "PASS") 
            && !isRegistered(client)) {
            // Send error: not registered
            return;
        }
        (this->*commandMap[command])(client, msg);
    }
}

bool CommandParser::isValidNickname(const std::string& nick) {
    if (nick.empty() || nick.length() > 9)
        return false;
    
    // First character must be a letter
    if (!isalpha(nick[0]))
        return false;
    
    // Rest can be letters, numbers, or special characters
    for (size_t i = 1; i < nick.length(); ++i) {
        char c = nick[i];
        if (!isalnum(c) && c != '-' && c != '_' && c != '[' && c != ']' 
            && c != '{' && c != '}' && c != '\\' && c != '`' && c != '|')
            return false;
    }
    return true;
}

bool CommandParser::isValidChannelName(const std::string& channel) {
    if (channel.empty() || channel.length() > 50)
        return false;
    
    // Must start with # or &
    if (channel[0] != '#' && channel[0] != '&')
        return false;
    
    // Cannot contain spaces, commas, or control characters
    for (size_t i = 1; i < channel.length(); ++i) {
        if (channel[i] == ' ' || channel[i] == ',' || channel[i] == 7)
            return false;
    }
    return true;
}

bool CommandParser::hasRequiredParams(const Message& msg, size_t required) {
    return (msg.getParams().size() + (msg.getTrailing().empty() ? 0 : 1)) >= required;
}

bool CommandParser::isRegistered(const Client& client) const {
    (void)client;
    // check if client is registered, for now returns true as a placeholder
    return true;
}

// void CommandParser::handleNick(Client& client, const Message& msg) {
//     (void)client;
//     if (!hasRequiredParams(msg, 1)) {
//         // Send ERR_NONICKNAMEGIVEN
//         return;
//     }

//     std::string newNick = msg.getParams()[0];
//     if (!isValidNickname(newNick)) {
//         // Send ERR_ERRONEUSNICKNAME
//         return;
//     }

//     // Check if nickname is already in use
//     // Set new nickname
//     // Broadcast nickname change if client was already registered
// }