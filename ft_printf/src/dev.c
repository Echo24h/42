#include "utils.h"

void	print_flags(t_flags flags)
{
	printf("flags.minus:%d\n", flags.minus);
	printf("flags.plus:%d\n", flags.plus);
	printf("flags.zero:%d\n", flags.zero);
	printf("flags.blank:%d\n", flags.blank);
	printf("flags.hashtag:%d\n", flags.hashtag);
}

void	print_opts(t_opts opts)
{
	printf("=== OPTS ===\n");
	printf("opts.width:%d\n", opts.width);
	printf("opts.precision:%d\n", opts.precision);
	print_flags(opts.flags);
	printf("=== OPTS ===\n");
}
