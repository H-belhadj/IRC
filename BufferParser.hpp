/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BufferParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:41:47 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:41:49 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_PARSER_HPP
#define BUFFER_PARSER_HPP

#include <string>
#include <queue>
#include "Message.hpp"

class BufferParser {
private:
    std::string buffer;
    const size_t MAX_MESSAGE_LENGTH;
    
public:
    BufferParser(size_t maxLength = 512);
    ~BufferParser();
    
    // Add data to buffer and get complete messages
    std::queue<Message> addData(const std::string& data);
    
    // Clear buffer
    void clear();
    
    // Check if buffer contains complete message
    bool hasCompleteMessage() const;
};

#endif