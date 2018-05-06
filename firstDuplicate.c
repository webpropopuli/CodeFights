/* All the "clever" solutions seem to think flipping nums negative is awesome but it feels
 * like a dirty hack to me. If this input was of an unknown size, I might look at it, but
 * at 100,000 max elements, this works and passes all size and speed tests.
 * 
 * Also, my gut tells me it might be better to flip on/off higher order bits (xf0 0000 or greater) and
 * use read/set with a mask/or combination. I "think" that's faster than a multiply (though the
 * compiler might optimize "x*-1" to the same thing - flipping the top bit)
 */
int firstDuplicate(arr_integer a) {

int len = a.size;
int z[100001] = {0};    //prob constraint say max is 10^5 so this seems reasonable
    
if(len <2)
    return -1;  //special case too small
    
int *X, *Y;

int *Y_end = a.arr+len;

Y = a.arr;

while (Y < Y_end)
    {
    if(z[*Y])
        return (*Y);
    else
        z[*Y] = 1;
 
    Y++;
    }

// default rv - not found
return (-1);    
}
/* What I learned:
1) rtfm then rtfm again. If I'd seen the 10^5 constraint early, this would have been my first try. 
	My first solution took 5 minutes and passed all but the runtime test, but I spent a boatload more time
	re-writing and trying to 'patch' that solution, rather then starting clean. I do that a lot....
2) The "smart money" isn't always so smart. If people are 'n'-smart, they will trip over themselves for anything
	that is merely "n+1"-smart, missing the chance of discovering an "n^2"-smart solution.
3) I've been guilty of #2
4) This ain't HackerRank...
 -Marlowe
/