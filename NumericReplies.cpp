/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericReplies.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:42:36 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:42:37 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumericReplies.hpp"

namespace NumericReplies {
    std::string RPL_WELCOME(const std::string& nick) {
        return "001 " + nick + " :Welcome to the Internet Relay Network " + nick;
    }
    
    std::string ERR_NOSUCHNICK(const std::string& nick) {
        return "401 " + nick + " :No such nick/channel";
    }
    
    std::string ERR_NOSUCHCHANNEL(const std::string& channel) {
        return "403 " + channel + " :No such channel";
    }
    
    // Implement other numeric replies...
}