/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserParser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:46:40 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 16:50:04 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef USER_PARSER_HPP
#define USER_PARSER_HPP

#include <string>

class UserParser {
public:
    // Parse user masks (nick!user@host)
    static bool parseUserMask(const std::string& mask, 
                            std::string& nick,
                            std::string& user,
                            std::string& host);
    
    // Validate username
    static bool isValidUsername(const std::string& username);
    
    // Parse user modes (+i, +w, etc.)
    static std::pair<bool, std::string> parseUserModes(const std::string& modes);
};
#pragma endregion