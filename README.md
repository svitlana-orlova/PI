## PI

> This repository is entirely dedicated to the `PI` numbers calculation.

## Why ?

I didn't think it could be so difficult to calculate a specific number
of digits for `π`.

## First implementations

As always the famous "someone else" [had such](https://crypto.stanford.edu/pbc/notes/pi/code.html) a problem.

Their solution is entirely based on *Dik T. Winter's* C program to compute the
first 800 digits of pi. Which looks like this:

```c
int a=10000,b,c=2800,d,e,f[2801],g;main(){for(;b-c;)f[b++]=a/5;
for(;d=0,g=c*2;c-=14,printf("%.4d",e+d/a),e=d%a)for(b=c;d+=f[b]*a,
f[b]=d%--g,d/=g--,--b;d*=b);}
```


