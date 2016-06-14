def is_word(word):
    #print word
    dict = list()
    dict.append("i")
    dict.append("am")
    dict.append("hat")
    dict.append("hate")
    
    if word in dict:
        return True
    else:
        return False
        
        
def is_sentence(sentence, start, end):
    '''
    i = 0
    j = 1
    isSentence = False
    
    while (j <= len(sentence)):
        if is_word(sentence[i:j]):
            i = j
            j = i + 1 #
            isSentence = True
            
        else:
            j += 1
            isSentence = False
            
    return isSentence
    '''
    
    if end <= start:
        return False
    
    if is_word(sentence[start:end]):
        return True
        
    x = end - start - 1
    y = 1
    while x > 0:
        #print sentence[start:end - x]
        #print sentence[start + y: end]
        #print "------"
        if (is_sentence(sentence, start, end - x) & is_sentence(sentence, start + y , end)):
            return True
        x -= 1
        y += 1
    
    return False
    

sent = "amhate"
if is_sentence(sent, 0, len(sent)):
    print "Is a sentence"
else:
    print "Not a sentence"