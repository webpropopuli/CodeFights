/* Man, this is ugly
 * Sometimes, you just want to get the damn thing done. This is one of those times.
 * Used JS for because it has a built-in sort() then I kicked myself for a half hour wishing I'd
 * just used my goto language, C.
 * But forcing myself to use JS or C# or whatever is part of the learn process and I'd never seen apply() before
 * so I learned something new.
 * As clean code goes, this is a junkyard and I'm balancing my need to tweak against the need to move forward.
 *
 * What I learned:
1) OMG, will you read the damn reqs? Once again, I had a "solution" in 5 minutes until I noticed that they asked for
	the first occurrence in the original string, not the first letter alphabetically. Derp.
	To be fair, I mainly get into this mess for these "gamified" code challenges. On "real" projects, I do step back and
	whiteboard/notebook the problem first. Something about these online things.....
2) In C this is a simple 26 element array with counters maybe. Hacking at it in JS was just awful
3) Start on paper. I know, I already said this but man, this code is so bad
4) Is it better to get more challenges done or to get fewer challenges "perfect"? My gut says make progress, GTD, 	
	have something to show for the time spent; my inner perfectionst says if you wouldn't eat it, don't serve it. But failing fast is better, esp in this environment where production is everything.
5) I hate JS and need to commit time to it even while CareerDevs is pushing C#, C, Python and whatever else. I think
	- and *please tell me if I'm wrong - JS is a must-know language in this full-stack world
6) I don't really hate you, JS, I'm just a little frustrated. We'll make it work...
 -Marlowe
 */
function firstNotRepeatingCharacter(s) {
arr = s.split('').sort();
//console.log(arr);
let x = 0;

let ltr = '';
let singlesArr = [];

// Walking the sorted array...    
while(x < arr.length) {
    ltr = arr[x];
    
    x++;
    
    // if we have a match then we don't care about this letter.
    if(ltr == arr[x])
        do {
         x++;   // eay any further matches will moving forward
        } while (ltr == arr[x]);
    // When we find a single, add it to a collections of single letters
    else
        singlesArr.push(ltr);
    }
    
//console.log("singles= " +singlesArr);

    
if(singlesArr.length == 0)          // no singles found
    return '_';
else if(singlesArr.length == 1)     // only one? that's our guy
    return singlesArr[0];
else
    {
    // find the match with the lowest index in orig string
    for(y = 0; y< singlesArr.length; y++)
        {
        singlesArr[y] = s.indexOf(singlesArr[y]);
        }
    return (s[Math.min.apply(null, singlesArr)]);
    }
    
} //omg, why didn't I do this in C?