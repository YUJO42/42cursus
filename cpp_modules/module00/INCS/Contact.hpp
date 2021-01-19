#ifndef CONTACT_HPP
# define CONTACT_HPP

// LIBS ========================================================================
# include <iostream>

// PROTOTYPES ==================================================================
class Contact;

// CLASS DEFINITIONS ===========================================================
// https://see-ro-e.tistory.com/33?category=778759
class Contact
{
	private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _login;
        std::string _postal_address;
        std::string _email_address;
        std::string _phone_number;
        std::string _birthday_date;
        std::string _favorite_meal;
        std::string _underwear_color;
        std::string _darkest_secret;
        bool        _is_empty;

    // overloading
    // https://blog.hexabrain.net/177
    // https://edykim.com/ko/post/c-operator-overloading-guidelines/

    // reference variable
    // https://boycoding.tistory.com/207

    // pass by reference
    // https://boycoding.tistory.com/217

	public:
		// constructor
        // https://effectivesquid.tistory.com/entry/C%EC%9D%98-%ED%81%B4%EB%9E%98%EC%8A%A4-%EC%83%9D%EC%84%B1%EC%9E%90-%EC%86%8C%EB%A9%B8%EC%9E%90
		Contact();
        // Copy Constructor
        // http://blog.naver.com/PostView.nhn?blogId=vgb910526&logNo=220665266599
        // http://www.soen.kr/lecture/ccpp/cpp3/26-2-2.htm
		Contact(const Contact&);

        // virtual deductor
        // https://yonmy.com/archives/36
        virtual ~Contact();

        // operator overloading
        Contact &operator=(const Contact& op);

		// setter(mutater)
		void    setFirstName(const std::string &first_name);
        void    setLastName(const std::string &last_name);
        void    setNickname(const std::string &nickname);
        void    setLogin(const std::string &login);
        void    setPostalAddress(const std::string &postal_address);
        void    setEmailAddress(const std::string &email_address);
        void    setPhoneNumber(const std::string &phone_number);
        void    setBirthdayDate(const std::string &birthday_date);
        void    setFavoriteMeal(const std::string &favorite_meal);
        void    setUnderwearColor(const std::string &underwear_color);
        void    setDarkestSecret(const std::string &darkest_secret);

		// getter(accesser)
        const std::string    &getFirstName();
        const std::string    &getLastName();
        const std::string    &getNickname();
        const std::string    &getLogin();
        const std::string    &getPostalAddress();
        const std::string    &getEmailAdress();
        const std::string    &getPhoneNumber();
        const std::string    &getBirthdayDate();
        const std::string    &getFavoriteMeal();
        const std::string    &getUnderwearColor();
        const std::string    &getDarkestSecret();

		// addon
		bool	empty(void);
		void	clear(void);
		void	setup(void);
        void    print_contact(void);
};

#endif
