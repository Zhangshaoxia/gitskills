//
//  lancode.h
//  testCheckString
//
//  Created by zhangshaoxia on 16/7/29.
//  Copyright © 2016年 etres. All rights reserved.
//

#ifndef lancode_h
#define lancode_h
enum
{
    Symbol,
    English,
    Jiaming,
    Korean,
    Hanzi,
    Russia,
    Bulgarian,
    Macedonian,
    SerbianCyrillic,
    Ukrainian,
    BelarussianCyrillic,
    AzerbaijaniCyrillic,
    Armenian,
    Greek,
    Vietnamese,
    France,
    Spain,
    Portuguese,
    German,
    Italy,
    Dutch,
    Swedish,
    Finnish,
    Danish,
    Norwegian,
    Hungarian,
    SerbianLatin,
    Afrikaans,
    Albanian,
    Basque,
    Catalan,
    Croatian,
    Czech,
    Estobnian,
    Icelandic,
    Indonesian,
    Irish,
    Latin,
    Latvian,
    Lithuanian,
    Malay,
    Polish,
    Romanian,
    Slovak,
    Slovenian,
    Turkish,
    Maltese,
    HaitianCreole,
    Galician,
    Filipino,
    Esperanto,
    BelarussianLatin,
    AzerbaijaniLatin
}
LANGUAGES_TYPE;



int isKorean(unsigned short curCode)//韩语
{
    return (( curCode >= 0x3130 && curCode <= 0x318e) || (curCode >= 0xAC00 && curCode <= 0xD7A3)) ? 1 : 0 ;
}


int isJiaMing(unsigned short curCode)//日语中的假名
{
    return ( (0x3041 <= curCode && 0x309E >= curCode )|| ( 0x30A1 <= curCode && 0x30FE >= curCode ) ) ? 1 : 0;
}

int isHanzi(unsigned short curCode)//汉字，包括日文和韩文中的汉字
{
    return (curCode >= 0x4e00 && !(curCode >= 0xff01 && curCode <= 0xff5e))?1:0;
    //		return 1;
}


int isEng(unsigned short curCode)//英语
{
    return ( ( 'A' <= curCode && 'Z' >= curCode ) || ( 'a' <= curCode && 'z' >= curCode ) ) ? 1 : 0;
}


//每个bloc {} 对应种语言unicode的范围
//有些语言会跟英语重合，比如法语也有‘A'等等，所以传入的英语字符按照以下函数，会被判断为英语。但为了表示完整，在每一个block中，还是
//将英语的判断逻辑加上，供调用者参考和调整

int GetLanguageCode(unsigned short candiCode)
{
    
    if (isEng(candiCode))
    {
        return English;
    }
    if (candiCode == 0xa2//￠
        || candiCode == 0xa3//￡
        || candiCode == 0xa5//￥ japan Yen symbol
        || candiCode == 0xa7//§
        || candiCode == 0xa9//? copyright symbol
        || candiCode == 0xab//<<
        || candiCode == 0xae//? register symbol
        || candiCode == 0xbb//>>
        || candiCode == 0x20ac// Euro symbol
        || candiCode == 0x20a9// korean Yuan symbol
        || candiCode == 0xffe5// RMB symbol
        )
        return Symbol;
    
    {//俄语
        if ( (candiCode >= 0x0410 && candiCode <= 0x0430)
            || candiCode == 0x0435
            || candiCode == 0x003c
            || candiCode == 0x003e
            || candiCode == 0x00ab
            || candiCode == 0x00bb
            || candiCode == 0x0401
            || candiCode == 0x0451
            )
        {
            return Russia;
        }
    }
    
    {
        if ( (candiCode >= 0x0410
              && candiCode <= 0x0430
              && candiCode != 0x042b
              && candiCode != 0x042d)
            || candiCode == 0x003c
            || candiCode == 0x003e
            || candiCode == 0x00ab
            || candiCode == 0x00bb
            || candiCode == 0x0435)
        {
            return Bulgarian;
        }
    }
    {
        if ( (candiCode >= 0x0410 && candiCode <= 0x0430
              && candiCode != 0x0419
              && candiCode != 0x0429
              && candiCode != 0x042a
              && candiCode != 0x042b
              && candiCode != 0x042c
              && candiCode != 0x042d
              && candiCode != 0x042e
              && candiCode != 0x042f)
            || candiCode == 0x0435
            || candiCode == 0x003c
            || candiCode == 0x003e
            || candiCode == 0x00ab
            || candiCode == 0x00bb
            || candiCode == 0x0403
            || candiCode == 0x0405
            || candiCode == 0x0408
            || candiCode == 0x0458
            || candiCode == 0x0409
            || candiCode == 0x040a
            || candiCode == 0x040c
            || candiCode == 0x040f
            
            )
        {
            return Macedonian;
        }
        
    }
    
    {
        if ( (candiCode >= 0x0410 && candiCode <= 0x0430
              && candiCode != 0x0419
              && candiCode != 0x0429
              && candiCode != 0x042a
              && candiCode != 0x042b
              && candiCode != 0x042c
              && candiCode != 0x042d
              && candiCode != 0x042e
              && candiCode != 0x042f)
            || candiCode == 0x003c
            || candiCode == 0x003e
            || candiCode == 0x00ab
            || candiCode == 0x00bb
            || candiCode == 0x0435
            || candiCode == 0x0402
            || candiCode == 0x0452
            || candiCode == 0x0408
            || candiCode == 0x0458
            || candiCode == 0x0409
            || candiCode == 0x040a
            || candiCode == 0x040b
            || candiCode == 0x040f
            )
        {
            return SerbianCyrillic;
        }
    }
    
    {
        if ( (candiCode >= 0x0410 && candiCode <= 0x0430
              && candiCode != 0x042a
              && candiCode != 0x042b
              && candiCode != 0x042e
              && candiCode != 0x042f)
            || candiCode == 0x0435
            || candiCode == 0x003c
            || candiCode == 0x003e
            || candiCode == 0x00ab
            || candiCode == 0x00bb
            || candiCode == 0x0404
            || candiCode == 0x0406
            || candiCode == 0x0456
            || candiCode == 0x0407
            || candiCode == 0x0457
            )
        {
            return Ukrainian;
        }
    }
    
    {
        if ( candiCode == 0x401
            || candiCode == 0x406
            || candiCode == 0x40e
            || ( candiCode >= 0x410 && candiCode <= 0x430 && candiCode != 0x429 && candiCode != 0x42a && candiCode != 0x42c )
            || candiCode == 0x435
            || candiCode == 0x451
            || candiCode == 0x456
            || candiCode == 0x490)
        {
            return BelarussianCyrillic;
        }
    }
    
    {
        if ( candiCode == 0x408
            || ( candiCode >= 0x410 && candiCode <= 0x42b && candiCode != 0x419 && candiCode != 0x426 && candiCode != 0x429 && candiCode != 0x42a )
            || candiCode == 0x430
            || candiCode == 0x435
            || candiCode == 0x458
            || candiCode == 0x492
            || candiCode == 0x49c
            || candiCode == 0x4ae
            || candiCode == 0x4b8
            || candiCode == 0x4ba
            || candiCode == 0x4d8
            || candiCode == 0x4e8)
        {
            return AzerbaijaniCyrillic;
        }
    }
    
    {
        if ( (candiCode >= 0x531 && candiCode <= 0x556)
            || candiCode == 0x561
            || candiCode == 0x566
            || candiCode == 0x570
            || candiCode == 0x571
            || candiCode == 0x575
            || candiCode == 0x577
            || candiCode == 0x579
            || candiCode == 0x57a
            || candiCode == 0x57c
            || candiCode == 0x57f
            || candiCode == 0x581
            || candiCode == 0x582
            || candiCode == 0x583
            )
        {
            return Armenian;
        }
    }
    
    {
        if (candiCode == 0x0386
            || candiCode == 0x0388
            || candiCode == 0x0389
            || candiCode == 0x038a
            || candiCode == 0x038c
            || candiCode == 0x038e
            || candiCode == 0x038f
            || candiCode == 0x0391
            || candiCode == 0x0392
            || candiCode == 0x0393
            || candiCode == 0x0394
            || candiCode == 0x0395
            || candiCode == 0x0396
            || candiCode == 0x0397
            || candiCode == 0x0398
            || candiCode == 0x0399
            || candiCode == 0x039a//0x03ba
            || candiCode == 0x039b
            || candiCode == 0x039c
            || candiCode == 0x039d
            || candiCode == 0x039e
            || candiCode == 0x03a0
            || candiCode == 0x03a1
            || candiCode == 0x03a3
            || candiCode == 0x03a4
            || candiCode == 0x03a5
            || candiCode == 0x03a6
            || candiCode == 0x03a7//0x03c7
            || candiCode == 0x03a8//0x03c8
            || candiCode == 0x03a9
            || candiCode == 0x03aa
            || candiCode == 0x03ab
            || candiCode == 0x03ac
            || candiCode == 0x03ad
            || candiCode == 0x03ae
            || candiCode == 0x03af
            || candiCode == 0x03b1
            || candiCode == 0x03b2
            || candiCode == 0x03b3
            || candiCode == 0x03b4
            || candiCode == 0x03b5
            || candiCode == 0x03b6
            || candiCode == 0x03b7
            || candiCode == 0x03b8
            || candiCode == 0x03b9
            || candiCode == 0x03bb
            || candiCode == 0x03bc
            || candiCode == 0x03bd
            || candiCode == 0x03be
            || candiCode == 0x03c0
            || candiCode == 0x03c1
            || candiCode == 0x03c2
            || candiCode == 0x03c3
            || candiCode == 0x03c4
            || candiCode == 0x03c5
            || candiCode == 0x03c6
            || candiCode == 0x03c9
            || candiCode == 0x03ca
            || candiCode == 0x03cb
            || candiCode == 0x03cc
            || candiCode == 0x03cd
            || candiCode == 0x03ce)
        {
            return Greek;
        }
        
    }
    
    
    {
        if ( (candiCode >= 0x0300
              && candiCode <= 0x0350) || isEng(candiCode))
        {
            return Vietnamese;
        }
        else if ( candiCode == 0x00c2
                 || candiCode == 0x00ca
                 || candiCode == 0x00d4
                 || candiCode == 0x00e2
                 || candiCode == 0x00ea
                 || candiCode == 0x01a0
                 || candiCode == 0x01af
                 || candiCode == 0x0110
                 || candiCode == 0x0111
                 || candiCode == 0x0102
                 || candiCode == 0x0103
                 )
        {
            return Vietnamese;
        }
        
        if (isEng(candiCode))
        {
            return Vietnamese;
        }
    }
    
    {
        if (candiCode == 0xc0
            || candiCode == 0xc2
            || candiCode == 0xc7
            || candiCode == 0xc8
            || candiCode == 0xc9
            || candiCode == 0xca
            || candiCode == 0xcb
            || candiCode == 0xce
            || candiCode == 0xcf
            || candiCode == 0xd4
            || candiCode == 0xd9
            || candiCode == 0xdb
            || candiCode == 0xe0
            || candiCode == 0xe2
            || candiCode == 0xe8
            || candiCode == 0xe9
            || candiCode == 0xea
            || candiCode == 0xeb
            || candiCode == 0xee
            || candiCode == 0xef
            || candiCode == 0xf9
            || candiCode == 0xfb
            )
            return France;
        
        if (isEng(candiCode))
        {
            return France;
        }
    }
    
    {
        if (candiCode == 0xc1
            || candiCode == 0xc9
            || candiCode == 0xcd
            || candiCode == 0xd1
            || candiCode == 0xd3
            || candiCode == 0xda
            || candiCode == 0xdc
            || candiCode == 0xe1
            || candiCode == 0xe9
            || candiCode == 0xed
            || candiCode == 0xf1
            || candiCode == 0xfa
            || candiCode == 0xfc
            )
            return Spain;
        
        if (isEng(candiCode))
        {
            return Spain;
        }
    }
    
    {
        if (candiCode == 0xc0
            || candiCode == 0xc1
            || candiCode == 0xc2
            || candiCode == 0xc3
            || candiCode == 0xc7
            || candiCode == 0xc9
            || candiCode == 0xca
            || candiCode == 0xcd
            || candiCode == 0xd1
            || candiCode == 0xd3
            || candiCode == 0xd4
            || candiCode == 0xd5
            || candiCode == 0xda
            || candiCode == 0xdc
            || candiCode == 0xe0
            || candiCode == 0xe1
            || candiCode == 0xe2
            || candiCode == 0xe3
            || candiCode == 0xe9
            || candiCode == 0xea
            || candiCode == 0xed
            || candiCode == 0xf1
            || candiCode == 0xfa
            || candiCode == 0xfc
            )
            return Portuguese;
        
        if (isEng(candiCode))
        {
            return Portuguese;
        }
    }
    
    {
        if (candiCode == 0xc4
            || candiCode == 0xd6
            || candiCode == 0xdc
            || candiCode == 0xdf
            || candiCode == 0xe4
            || candiCode == 0xfc
            )
            return German;
        
        if (isEng(candiCode))
        {
            return German;
        }
    }
    
    {
        if (candiCode == 0xc0
            || candiCode == 0xc8
            || candiCode == 0xc9
            || candiCode == 0xcc
            || candiCode == 0xd2
            || candiCode == 0xd9
            || candiCode == 0xe0
            || candiCode == 0xe8
            || candiCode == 0xe9
            || candiCode == 0xec
            || candiCode == 0xf9
            )
            return Italy;
        
        if (isEng(candiCode))
        {
            return Italy;
        }
    }
    
    {
        if (candiCode == 0xc1
            || candiCode == 0xc2
            || candiCode == 0xc4
            || candiCode == 0xc8
            || candiCode == 0xc9
            || candiCode == 0xca
            || candiCode == 0xcb
            || candiCode == 0xcd
            || candiCode == 0xcf
            || candiCode == 0xd3
            || candiCode == 0xd6
            || candiCode == 0xdc
            || candiCode == 0xe1
            || candiCode == 0xe2
            || candiCode == 0xe4
            || candiCode == 0xe8
            || candiCode == 0xe9
            || candiCode == 0xeb
            || candiCode == 0xed
            || candiCode == 0xef
            || candiCode == 0xfc
            )
            return Dutch;
        
        if (isEng(candiCode))
        {
            return Dutch;
        }
    }
    {
        if (candiCode == 0xc4
            || candiCode == 0xc5
            || candiCode == 0xd6
            || candiCode == 0xe4
            || candiCode == 0xe5
            )
            return Swedish;
        
        if (isEng(candiCode))
        {
            return Swedish;
        }
    }
    {
        if (candiCode == 0xc4
            || candiCode == 0xc5
            || candiCode == 0xd6
            || candiCode == 0xe4
            || candiCode == 0xe5
            )
            return Finnish;
        
        if (isEng(candiCode))
        {
            return Finnish;
        }
    }
    {
        if (candiCode == 0xc5
            || candiCode == 0xc6
            || candiCode == 0xd8
            || candiCode == 0xe5
            || candiCode == 0xe6
            )
            return Danish;
        
        if (isEng(candiCode))
        {
            return Danish;
        }
    }
    {
        if (candiCode == 0xc5
            || candiCode == 0xc6
            || candiCode == 0xd8
            || candiCode == 0xe5
            || candiCode == 0xe6
            )
            return Norwegian;
        
        if (isEng(candiCode))
        {
            return Norwegian;
        }
    }
    
    {
        if (candiCode == 0xc1
            || candiCode == 0xc9
            || candiCode == 0xcd
            || candiCode == 0xd3
            || candiCode == 0xd6
            || candiCode == 0xda
            || candiCode == 0xdc
            || candiCode == 0xe1
            || candiCode == 0xe9
            || candiCode == 0xed
            || candiCode == 0xfa
            || candiCode == 0xfc
            )
            return Hungarian;
        
        if (isEng(candiCode))
        {
            return Hungarian;
        }
    }
    
    
    
    {
        if (candiCode == 0x0110
            || candiCode == 0x0111
            || candiCode == 0x017d
            || candiCode == 0x0106
            || candiCode == 0x010c
            || candiCode == 0x0160
            || candiCode == 0x01c4
            || candiCode == 0x01c6
            || isEng(candiCode)
            )
        {
            return SerbianLatin;
        }
        
        if (isEng(candiCode))
        {
            return SerbianLatin;
        }
    }
    
    
    
    {
        if(candiCode == 202
           || candiCode == 234
           || candiCode == 203
           || candiCode == 235
           || candiCode == 212
           || candiCode == 219)
        {
            return Afrikaans;
        }
        
        if (isEng(candiCode))
        {
            return Afrikaans;
        }
    }
    
    {
        if(candiCode == 199
           || candiCode == 203
           || candiCode == 235)
        {
            return Albanian;
        }
        
        if (isEng(candiCode))
        {
            return Albanian;
        }
    }
    
    {
        if(candiCode == 199
           || candiCode == 209
           || candiCode == 241)
        {
            return Basque;
        }
        
        if (isEng(candiCode))
        {
            return Basque;
        }
    }
    
    {
        if(candiCode == 192 || candiCode == 224 || candiCode == 201 || candiCode == 233 || candiCode == 200 || candiCode == 232 || candiCode == 205 || candiCode == 207 || candiCode == 211 || candiCode == 210 || candiCode == 218 || candiCode == 220 || candiCode == 199)
        {
            return Catalan;
        }
        
        if (isEng(candiCode))
        {
            return Catalan ;
        }
    }
    
    {
        if(candiCode == 268 || candiCode == 262 || candiCode == 272 || candiCode == 273 || candiCode == 352 || candiCode == 381
           || candiCode == 0x1c4
           || candiCode == 0x1c6)
        {
            return Croatian;
        }
        
        if (isEng(candiCode))
        {
            return Croatian;
        }
    }
    
    {
        if(candiCode == 193 || candiCode ==	225 || candiCode ==	268 || candiCode ==	270 || candiCode ==	271 || candiCode ==	201 || candiCode ==	233 || candiCode ==	282 || candiCode ==	283 || candiCode ==	205 || candiCode ==	327 || candiCode ==	328 || candiCode ==	211 || candiCode ==	344 || candiCode ==	345 || candiCode ==	352 || candiCode ==	356 || candiCode ==	357 || candiCode ==	218 || candiCode ==	366 || candiCode ==	221 || candiCode ==	253 || candiCode ==	381)
        {
            return Czech;
        }
        
        if (isEng(candiCode))
        {
            return Czech;
        }
    }
    
    {
        if(candiCode == 352 || candiCode ==	381 || candiCode ==	213 || candiCode ==	196 || candiCode ==	214 || candiCode ==	220)
        {
            return Estobnian;
        }
        
        if (isEng(candiCode))
        {
            return Estobnian;
        }
        
    }
    
    {
        if(candiCode == 193 || candiCode ==	225 || candiCode ==	208 || candiCode ==	240 || candiCode ==	201 || candiCode ==	233 || candiCode ==	205 || candiCode ==	211 || candiCode ==	218 || candiCode ==	221 || candiCode ==	253 || candiCode ==	222 || candiCode ==	254 || candiCode ==	198 || candiCode ==	230 || candiCode ==	214)
        {
            return Icelandic;
        }
        
        if (isEng(candiCode))
        {
            return Icelandic;
        }
    }
    
    {
        if (isEng(candiCode))
        {
            return Indonesian;
        }
    }
    
    {
        if(candiCode == 193 || candiCode ==	225 || candiCode ==	201 || candiCode ==	233 || candiCode ==	205 || candiCode ==	211 || candiCode ==	218)
        {
            return Irish;
        }	
        
        if (isEng(candiCode))
        {
            return Irish;
        }
    }
    
    {//这个有问题 所有的we char 都过
        if (candiCode == 0x014c
            || candiCode == 0x01a0
            || candiCode == 0x01af)
        {
            return Latin;
        }
        
        if (isEng(candiCode))
        {
            return Latin;
        }
    }
    
    {
        if(candiCode == 256 || candiCode ==	257 || candiCode ==	268 || candiCode ==	274 || candiCode ==	275 || candiCode ==	290 || candiCode ==	291 || candiCode ==	298 || candiCode ==	310 || candiCode ==	315 || candiCode ==	316 || candiCode ==	325 || candiCode ==	326 || candiCode ==	352 || candiCode ==	362 || candiCode ==	381)
        {
            return Latvian;
        }
        
        if (isEng(candiCode))
        {
            return Latvian;
        }
    }
    
    {
        if(candiCode == 260 || candiCode ==	261 || candiCode ==	268 || candiCode ==	280 || candiCode ==	281 || candiCode ==	278 || candiCode ==	279 || candiCode ==	302 || candiCode ==	303 || candiCode ==	352 || candiCode ==	370 || candiCode ==	362 || candiCode ==	381)
        {
            return Lithuanian;
        }
        
        if (isEng(candiCode))
        {
            return Lithuanian;
        }
    }
    
    {
        if(candiCode == 260 || candiCode ==	261 || candiCode ==	262 || candiCode ==	280 || candiCode ==	281 || candiCode ==	321 || candiCode ==	322 || candiCode ==	323 || candiCode ==	324 || candiCode ==	211 || candiCode ==	346 || candiCode ==	377 || candiCode ==	379)
        {
            return Polish;
        }	
        
        if (isEng(candiCode))
        {
            return Polish;
        }
    }
    
    {
        if(candiCode == 258 || candiCode ==	259 || candiCode ==	194 || candiCode ==	226 || candiCode ==	206 || candiCode ==	536 || candiCode ==	538 || candiCode ==	539 || candiCode ==	350 || candiCode ==	354 || candiCode == 0x0163)
        {
            return Romanian;
        }	
        
        if (isEng(candiCode))
        {
            return Romanian;
        }
    }
    
    {
        if(candiCode == 193 || candiCode ==	225 || candiCode ==	196 || candiCode ==	228 || candiCode ==	201 || candiCode ==	233 || candiCode ==	205 || candiCode ==	211 || candiCode ==	212 || candiCode ==	218 || candiCode ==	221 || candiCode ==	268 || candiCode ==	270 || candiCode ==	271 || candiCode ==	381 || candiCode ==	313 || candiCode ==	314 || candiCode ==	317 || candiCode ==	318 || candiCode ==	327 || candiCode ==	328 || candiCode ==	340 || candiCode ==	341 || candiCode ==	352 || candiCode ==	356 || candiCode ==	357
           || candiCode == 0x1c4
           || candiCode == 0x1c6
           || candiCode == 0x1f1
           || candiCode == 0x1f3)
        {
            return Slovak;
        }	
        
        if (isEng(candiCode))
        {
            return Slovak;
        }
    }
    
    {
        if(candiCode == 268 || candiCode ==	352 || candiCode ==	381)
        {
            return Slovenian;
        }
        
        if (isEng(candiCode))
        {
            return Slovenian;
        }
    }
    
    
    {
        if(candiCode == 199 || candiCode ==	286 || candiCode ==	287 || candiCode ==	305 || candiCode ==	304 || candiCode ==	214 || candiCode ==	350 || candiCode ==	220)
        {
            return Turkish;
        }	
        
        if (isEng(candiCode))
        {
            return Turkish;
        }
    }
    {
        if (candiCode == 0x10a
            || candiCode == 0x120
            || candiCode == 0x121
            || candiCode == 0x126
            || candiCode == 0x127
            || candiCode == 0x17b)
        {
            return Maltese;
        }
        
        if (isEng(candiCode))
        {
            return Maltese;
        }
    }
    
    {
        if (candiCode == 0xc8
            || candiCode == 0xe8
            || candiCode == 0xd2)
        {
            return HaitianCreole;
        }
        
        if (isEng(candiCode))
        {
            return HaitianCreole;
        }
    }
    
    {
        if (candiCode == 0xd1
            || candiCode == 0xf1
            || candiCode == 0xe1
            || candiCode == 0xe9
            || candiCode == 0xed
            || candiCode == 0xf3
            || candiCode == 0xfa
            || candiCode == 0xc1
            || candiCode == 0xc9
            || candiCode == 0xcd
            || candiCode == 0xd3
            || candiCode == 0xda
            )
        {
            return Galician;
        }
        
        if (isEng(candiCode))
        {
            return Galician;
        }
    }
    
    {
        if (candiCode == 0xd1
            || candiCode == 0xf1)
        {
            return Filipino;
        }
        
        if (isEng(candiCode))
        {
            return Filipino;
        }
    }
    
    {
        if ( candiCode == 0x108
            || candiCode == 0x11c
            || candiCode == 0x11d
            || candiCode == 0x124
            || candiCode == 0x125
            || candiCode == 0x134
            || candiCode == 0x15c
            || candiCode == 0x16c )
        {
            return Esperanto;
        }
        
        if (isEng(candiCode))
        {
            return Esperanto;
        }
    }
    
    {
        if (candiCode == 0x10c
            || candiCode == 0x143
            || candiCode == 0x144
            || candiCode == 0x15a
            || candiCode == 0x160
            || candiCode == 0x16c
            || candiCode == 0x179
            || candiCode == 0x17d
            || candiCode == 0x1c4
            || candiCode == 0x1c6
            || candiCode == 0x1f1
            || candiCode == 0x1f3)
        {
            return BelarussianLatin;
        }
        
        if (isEng(candiCode))
        {
            return BelarussianLatin;
        }
    }
    
    {
        if (candiCode == 0x11e
            || candiCode == 0x11f
            || candiCode == 0x130
            || candiCode == 0x15e
            || candiCode == 0x18f
            || candiCode == 0xc4
            || candiCode == 0xc7
            || candiCode == 0xd6
            || candiCode == 0xdc
            || candiCode == 0xe4)
        {
            return AzerbaijaniLatin;
        }
        
        if (isEng(candiCode))
        {
            return AzerbaijaniLatin;
        }
    }
    
    if (isHanzi(candiCode))
    {
        
        return Hanzi;//包括中日韩语言中的汉字
        
    }
    
    if (isKorean(candiCode))
    {
        return Korean;
    }
    if (isJiaMing(candiCode))
    {
        return Jiaming;//日语中的假名
    }
    return 0;
}

#endif /* lancode_h */
