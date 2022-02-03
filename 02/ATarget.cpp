#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!\n";
}