#include <iostream>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		
	public:
		void	complain(std::string level);

	private:
		std::string	_levels[4];
		void		(Harl::*_func[4])(void);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
