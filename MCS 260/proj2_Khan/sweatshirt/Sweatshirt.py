def new_list2d(row,col):
    """this creates a structure into which row and col and can have number slots"""
    a = [[(0) for j in range(col)] for i in range(row)]
    return a

def get_inv(a,row,col):                     
    """Asks the front user how many shirts in each small meduim large xlarge dict
        for a college then repeat 7 times and stores the data."""
    size = {
    0 : " Small",
    1 : "Medium",
    2 : " Large",
    3 : "Xlarge"
    }

    for j in range(col):
        for i in range(row):
            a[i][j] = input("College %s,%s: " % (j+1, size[i])) 


def print_summarytwo(a,rs,cs,row,col,total):
    """This function prints the results given by get_inv"""
    size = {
    0 : "         Small",
    1 : "        Medium",
    2 : "         Large",
    3 : "        Xlarge"
    }
    i = 0
    print ""
    print "                              Inventory Report"
    print "                                  College"
    print "                   1    2    3    4    5    6    7 Size Total  "
    for i in range(row):
        print size[i],
        print "",

        for j in range(col):
            print " %3d" %(a[i][j]),
        print "   %d" %(rs[i])
        
        if i == 1:
            print "Size"
        else: 
            print ""
    print "College total  ",

    for j in range(col):
        print "%4d" %(cs[j]),
    print ""
    print "                             Total Quantity On Hand %3d" % total
     

def sum_1d(rs):
    """this function allows to get sum of the Total Quantity on Hand"""
    total = sum(rs)
    return total

def row_sum(a,row,col):
    """ allocate list b initialize to zero, store rows sums in b, return b , list of row
    sums"""
    b = [0 for i in range(row)]    #0  makes a intial list of [0,0,0,0]
    for i in range(row):
        s = 0                       #so the for loops has the begining iteration 
        for j in range(col):
            s = s + a[i][j]
        b[i] = s
    return b

def col_sum(a,row,col):
    """ allocate list c for columns, return c"""
    c = [0 for j in range(col)] 
    for j in range(col):
        s = 0 
        for i in range(row):
            s = s + a[i][j]
        c[j] = s
    return c 

            
            
def main():
    """THis is where the calls are cited""" 
    row = 4                     
    col = 7
    a = new_list2d(row,col)       # offical 4 by 8 structure
    
    get_inv(a,row,col)        #The g incapsulate the entire function of get_inv
    rs = row_sum(a,row,col)          #This allows a single letter to list properties
    cs = col_sum(a,row,col)
    total = sum_1d(rs)
    print_summarytwo(a,rs,cs,row,col,total)          

if __name__ == "__main__":  
    main()


