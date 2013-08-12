#ifndef _MUTATION_H_
#define _MUTATION_H_

#include "pldata.h"
#include <vector>

enum mutation_category
{
 MUTCAT_NULL = 0,
 MUTCAT_LIZARD,
 MUTCAT_BIRD,
 MUTCAT_FISH,
 MUTCAT_BEAST,
 MUTCAT_CATTLE,
 MUTCAT_INSECT,
 MUTCAT_PLANT,
 MUTCAT_SLIME,
 MUTCAT_TROGLO,
 MUTCAT_CEPHALOPOD,
 MUTCAT_SPIDER,
 MUTCAT_RAT,
 NUM_MUTATION_CATEGORIES
};

// mutations_from_category() defines the lists; see mutation_data.cpp
std::vector<std::string> mutations_from_category(mutation_category cat);

struct dream
{
  std::vector<std::string> message;			// The messages that the dream will give
  mutation_category category;	// The category that will trigger the dream
  int strength;					// The category strength required for the dream

  dream() {
  category = MUTCAT_NULL;
  strength = 0;
  }
};

extern std::vector<dream> dreams;

mutation_category string_to_mutcat(std::string input);

struct mutation_branch
{
 bool valid; // True if this is a valid mutation (only used for starting traits)
 std::vector<std::string> prereqs; // Prerequisites; Only one is required
 std::vector<std::string> cancels; // Mutations that conflict with this one
 std::vector<std::string> replacements; // Mutations that replace this one
 std::vector<std::string> additions; // Mutations that add to this one

 mutation_branch() { valid = false; };

};


#endif
