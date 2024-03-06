## PI

> This repository is entirely dedicated to the `PI` numbers calculation.

## Why ?

I didn't think it could be so difficult to calculate a specific number
of digits for `π`.

## Rabinowitz-Wagon Algorithm (PBC)

As always the famous "someone else" [had such](https://crypto.stanford.edu/pbc/notes/pi/code.html) a problem.

Their solution is entirely based on *Dik T. Winter's* C program to compute the
first 800 digits of pi. Which looks like this:

```c
int a=10000,b,c=2800,d,e,f[2801],g;main(){for(;b-c;)f[b++]=a/5;
for(;d=0,g=c*2;c-=14,printf("%.4d",e+d/a),e=d%a)for(b=c;d+=f[b]*a,
f[b]=d%--g,d/=g--,--b;d*=b);}
```

### Implementations:

  * [pbc_pi.c](c/pbc_pi.c)
  * [pbc_pi.js](js/pbc_pi.js)
  * [pbc_pi.pl](perl5/pbc_pi.pl)

*Fun fact* - each implementation generates different numbers.

## Gibbons' Streaming Algorithm (GIB)

Gibbons' later used the same expression to create their algorithm for the
digits of π:

```haskell
leibniz_pi = g(1,0,1,1,3,3) where
   g(q,r,t,k,n,l) = if 4*q+r-t<n*t
        then n : g(10*q,10*(r-n*t),t,k,div(10*(3*q+r))t-10*n,l)
             else g(q*k,(2*q+r)*l,t*l,k+1,div(q*(7*k+2)+r*l)(t*l),l+2)
             main = print (take 10 leibniz_pi)
```

### Implementations:

  * [lamberts_gib.py](references/lamberts_gib.py)
  * [gib_orig.hs](references/gib_orig.hs)

## Licence

GPLv2

