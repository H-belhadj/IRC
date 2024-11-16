/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericReplies.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:42:24 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:42:26 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMERIC_REPLIES_HPP
#define NUMERIC_REPLIES_HPP

#include <string>

namespace NumericReplies {
    // Registration responses
    std::string RPL_WELCOME(const std::string& nick);
    std::string RPL_YOURHOST(const std::string& servername, const std::string& version);
    std::string RPL_CREATED(const std::string& date);
    std::string RPL_MYINFO(const std::string& servername, const std::string& version,
                          const std::string& userModes, const std::string& channelModes);

    // Error responses
    std::string ERR_NOSUCHNICK(const std::string& nick);
    std::string ERR_NOSUCHCHANNEL(const std::string& channel);
    std::string ERR_CANNOTSENDTOCHAN(const std::string& channel);
    std::string ERR_NORECIPIENT(const std::string& command);
    std::string ERR_NOTEXTTOSEND();
    std::string ERR_UNKNOWNCOMMAND(const std::string& command);
    std::string ERR_NONICKNAMEGIVEN();
    std::string ERR_ERRONEUSNICKNAME(const std::string& nick);
    std::string ERR_NICKNAMEINUSE(const std::string& nick);
    std::string ERR_NOTREGISTERED();
    // Add more as needed...
};

#endif