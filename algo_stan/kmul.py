def kmul(n1,n2,n):
    if n == 1:
        return n1*n2
    else:
        a = n1/(10**(n/2))
        b = n1%(10**(n/2))
        c = n2/(10**(n/2))
        d = n2%(10**(n/2))
        ac = kmul(a,c,n/2)
        bd = kmul(b,d,n/2)
        abcd = kmul(a+b,c+d,n/2)
        adbc = abcd - ac - bd
        return ac*(10**n)+adbc*(10**(n/2))+bd

