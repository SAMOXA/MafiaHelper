var origText = "Rosemary Fell was not exactly beautiful. She was young, brilliant, extremely modern, well dressed and amazingly well read in the newest of the new books. Rosemary had been married two years, and her husband was very fond of her. They were rich, really rich, not just comfortably well-off, so if Rosemary wanted to shop, she would go to Paris as you and I would go to Bond Street. One winter afternoon she went into a small shop to look at a little box which the shopman had been keeping for her. He had shown it to nobody as yet so that she might be the first to see it. Charming! Rosemary admired the box. But how much would he charge her for it? For a moment the shopman did not seem to hear. The lady could certainly afford a high price. Then his words reached her, Twenty-eight guineas, madam. Twenty-eight guineas. Rosemary gave no sign. Even if one is rich... Her voice was dreamy as she answered: Well, keep it for me, will you? I'll... The shopman bowed. He would be willing of course, to keep it for her forever. Outside rain was falling, there was a cold, bitter taste in the air, and the newly lighted lamps looked sad... At that very moment a young girl, thin, dark, appeared at Rosemary's elbow and a voice, like a sigh, breathed: Madam, may I speak to you a moment?"

function findBeginAfter(offset){
    var i = offset;
    var upperCase = /[A-Z]/
    for(i=0;i<origText.length;i++){
        if(upperCase.test(origText.charAt(i))){
            break;
        }
    }
    return i;
}

function generateText(parentWidth, parentHeight, elementWidth, elementHeight, offset, spacing, beginFromUpperCase) {
    var i
    if(beginFromUpperCase === true){
        i = findBeginAfter(offset)
    }else{
        i = offset
    }
    var x
    var y
    var upperCase = /[A-Z]/
    var countX = Math.floor(parentWidth/elementWidth)
    var addX = Math.round(parentWidth-(countX*elementWidth))
    var countY = Math.floor(parentHeight/(elementHeight+spacing))
    var output = new Array(countY)
    for(y=0;y<countY;y++){
        if(addX !== 0){
            output[y] = new Array(countX+1)
        }else{
            output[y] = new Array(countX)
        }
        for(x=0;x<countX;x++){
            if(upperCase.test(origText.charAt(i))){
                output[y][x] = 2
            }else{
                if(origText.charAt(i) === ' '){
                    output[y][x] = 0
                }else{
                    output[y][x] = 1
                }
            }
            i++;
        }
        if(addX !== 0){
            if(origText.charAt(i) === ' '){
                output[y][x] = -addX
            }else{
                output[y][x] = -addX
            }
            i++
        }
    }
    return output
}
