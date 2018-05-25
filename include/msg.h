/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** msg.h
*/

#ifndef MSG_H_
# define MSG_H_

# define m431 "431 NICK : No nickname given\r\n"
# define m433 "433 NICK : Nickname is already in use\r\n"
# define m433 "432 NICK : Erroneus nickname\r\n"
# define m400 "400 : Too much users connected\r\n"
# define m421 "421 Unknown command\r\n"
# define m321 "321 List Start: Channel:Users Name\r\n"
# define m322 "322 %s\r\n"
# define m323 "323 End of /LIST\r\n"
# define m442 "442 NAMES : You're not on that channel\r\n"
# define m353 "353 %s: [@%s]\r\n"
# define m366 "366 End of /NAMES list\r\n"
# define m461 "461 JOIN : Not enough parameters\r\n"
# define m403 "403 JOIN : Not such channel\r\n"
# define m442 "442 PART : You're not on that channel\r\n"

#endif /* !MSG_H_ */
