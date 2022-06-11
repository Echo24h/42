#include <iostream>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		
		void	complain(std::string level);

	private:
		std::string	_levels[4];
		void		(Harl::*_func[4])(void);

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
