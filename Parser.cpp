/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:39:54 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:13 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parser.cpp
#include "Parser.hpp"
#include <algorithm>
#include <sstream>

std::string Parser::trimString(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

std::vector<std::string> Parser::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        if (!token.empty())
            tokens.push_back(token);
    }
    
    return tokens;
}

bool Parser::isValidMessage(const std::string& message) {
    // Check message length (512 bytes including \r\n)
    if (message.length() > 510) // 512 - 2 for \r\n
        return false;
        
    // Check for required \r\n ending
    if (message.length() < 2 || message.substr(message.length() - 2) != "\r\n")
        return false;
        
    return true;
}

Message Parser::parseMessage(const std::string& raw_message) {
    Message msg;
    std::string message = trimString(raw_message);
    
    // Remove \r\n if present
    if (message.length() >= 2 && message.substr(message.length() - 2) == "\r\n")
        message = message.substr(0, message.length() - 2);
    
    // Handle prefix (if exists)
    if (!message.empty() && message[0] == ':') {
        size_t space_pos = message.find(' ');
        if (space_pos != std::string::npos) {
            msg.setPrefix(message.substr(1, space_pos - 1));
            message = message.substr(space_pos + 1);
        }
    }
    
    // Find trailing parameter (if exists)
    size_t trailing_pos = message.find(" :");
    std::string trailing;
    if (trailing_pos != std::string::npos) {
        trailing = message.substr(trailing_pos + 2);
        message = message.substr(0, trailing_pos);
    }
    
    // Split remaining message into command and parameters
    std::vector<std::string> parts = splitString(message, ' ');
    if (!parts.empty()) {
        msg.setCommand(parts[0]);
        for (size_t i = 1; i < parts.size(); ++i)
            msg.addParam(parts[i]);
    }
    
    // Set trailing if it exists
    if (!trailing.empty())
        msg.setTrailing(trailing);
    
    return msg;
}