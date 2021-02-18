/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Gates.c++
*/

#include "Gates.hpp"

nts::Tristate nts::Gates::andGate(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == TRUE && state2 == TRUE)
        return TRUE;
    else if (state1 == FALSE || state2 == FALSE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::reverseState(nts::Tristate tristate)
{
    switch (tristate) {
    case TRUE:
        return FALSE;
    case FALSE:
        return TRUE;
    default:
        return UNDEFINED;
    }
}

nts::Tristate nts::Gates::xorGate(nts::Tristate state1, nts::Tristate state2)
{
    if ((state1 == TRUE && state2 == FALSE) ||
        (state1 == FALSE && state2 == TRUE))
        return TRUE;
    else if ((state1 == TRUE && state2 == TRUE) ||
        (state1 == FALSE && state2 == FALSE))
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::orGate(nts::Tristate state1, nts::Tristate state2)
{
    if (state1 == TRUE || state2 == TRUE)
        return TRUE;
    else if (state1 == FALSE && state2 == FALSE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::anyTrue(nts::Tristate one, nts::Tristate two,
    nts::Tristate three, nts::Tristate four)
{
    if (one == FALSE && two == FALSE && three == FALSE && four == FALSE)
        return (TRUE);
    else if (one == TRUE || two == TRUE || three == TRUE || four == TRUE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::oneTrue(nts::Tristate one, nts::Tristate two,
    nts::Tristate three, nts::Tristate four)
{
    if (one == TRUE && two == FALSE && three == FALSE && four == FALSE)
        return (TRUE);
    else if (one == FALSE || two == TRUE || three == TRUE || four == TRUE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::twoTrue(nts::Tristate one, nts::Tristate two,
    nts::Tristate three, nts::Tristate four)
{
    if (one == TRUE && two == TRUE && three == FALSE && four == FALSE)
        return (TRUE);
    else if (one == FALSE || two == FALSE || three == TRUE || four == TRUE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::threeTrue(nts::Tristate one, nts::Tristate two,
    nts::Tristate three, nts::Tristate four)
{
    if (one == TRUE && two == TRUE && three == TRUE && four == FALSE)
        return (TRUE);
    else if (one == FALSE || two == FALSE || three == FALSE || four == TRUE)
        return FALSE;
    else
        return UNDEFINED;
}

nts::Tristate nts::Gates::fourTrue(nts::Tristate one, nts::Tristate two,
    nts::Tristate three, nts::Tristate four)
{
    if (one == TRUE && two == TRUE && three == TRUE && four == TRUE)
        return (TRUE);
    else if (one == FALSE || two == FALSE || three == FALSE || four == FALSE)
        return FALSE;
    else
        return UNDEFINED;
}


