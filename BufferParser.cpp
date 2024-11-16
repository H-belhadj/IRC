/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BufferParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:41:57 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:41:59 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BufferParser.hpp"
#include "Parser.hpp"

BufferParser::BufferParser(size_t maxLength) : MAX_MESSAGE_LENGTH(maxLength) {}

BufferParser::~BufferParser() {}

std::queue<Message> BufferParser::addData(const std::string& data) {
    std::queue<Message> messages;
    buffer += data;
    
    // Process buffer for complete messages
    while (hasCompleteMessage()) {
        size_t pos = buffer.find("\r\n");
        std::string messageStr = buffer.substr(0, pos + 2);
        
        // Remove processed message from buffer
        buffer = buffer.substr(pos + 2);
        
        // Parse message if it's valid
        if (Parser::isValidMessage(messageStr)) {
            messages.push(Parser::parseMessage(messageStr));
        }
        
        // Check for buffer overflow
        if (buffer.length() > MAX_MESSAGE_LENGTH) {
            buffer.clear();
            break;
        }
    }
    
    return messages;
}

void BufferParser::clear() {
    buffer.clear();
}

bool BufferParser::hasCompleteMessage() const {
    return buffer.find("\r\n") != std::string::npos;
}