/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelParser.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:46:12 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 18:38:40 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_PARSER_HPP
#define CHANNEL_PARSER_HPP

#include <string>
#include <vector>

class ChannelParser {
private:
    static bool isValidModeString(const std::string& modes);

public:
    // Parse channel list (for JOIN command)
    static std::vector<std::string> parseChannelList(const std::string& channels);
    
    // Parse channel modes (+o, +v, etc.)
    static std::pair<std::string, std::vector<std::string> > parseChannelModes(const std::string& modestring);
    
    // Parse ban masks
    static bool isValidBanMask(const std::string& mask);
    
    // Check if user matches ban mask
    static bool matchBanMask(const std::string& mask, const std::string& nickname,
                            const std::string& username, const std::string& hostname);
    static bool isValidModeChar(char c);
};
#endif