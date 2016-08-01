//
//  ViewController.m
//  testCheckString
//
//  Created by zhangshaoxia on 16/7/29.
//  Copyright © 2016年 etres. All rights reserved.
//

#import "ViewController.h"
#import "Language.c"

#define width [UIScreen mainScreen].bounds.size.width
#define height [UIScreen mainScreen].bounds.size.height
#define languageArr @[@"Symbol",@"English",@"Jiaming",@"Korean",@"Hanzi",@"Russia",@"Bulgarian",@"Macedonian",@"SerbianCyrillic",@"Ukrainian",@"BelarussianCyrillic",@"AzerbaijaniCyrillic",@"Armenian",@"Greek",@"Vietnamese",@"France",@"Spain",@"Portuguese",@"German",@"Italy",@"Dutch",@"Swedish",@"Finnish",@"Danish",@"Norwegian",@"Hungarian",@"SerbianLatin",@"Afrikaans",@"Albanian",@"Basque",@"Catalan",@"Croatian",@"Czech",@"Estobnian",@"Icelandic",@"Indonesian",@"Irish",@"Latin",@"Latvian",@"Lithuanian",@"Malay",@"Polish",@"Romanian",@"Slovak",@"Slovenian",@"Turkish",@"Maltese",@"Galician",@"Filipino",@"Esperanto",@"BelarussianLatin",@"AzerbaijaniLatin"]
@interface ViewController ()<UITextFieldDelegate>
@property (nonatomic, strong) UITextField * textField;
@property (nonatomic, strong) UILabel * tipLabel;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor whiteColor];
    self.textField = [[UITextField alloc] initWithFrame:CGRectMake(50, 100, width-100, 50)];
    self.textField.placeholder = @"请出入字符串";
    self.textField.layer.borderWidth = 1;
    self.textField.layer.borderColor = [UIColor blueColor].CGColor;
    self.textField.delegate = self;
    [self.view addSubview:self.textField];
    
    self.tipLabel = [[UILabel alloc] initWithFrame:CGRectMake(50, 250, width-100, 50)];
    self.tipLabel.textColor = [UIColor redColor];
    self.tipLabel.font = [UIFont boldSystemFontOfSize:20];
    self.tipLabel.backgroundColor = [UIColor clearColor];
    self.tipLabel.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:self.tipLabel];
}


- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
//    self.tipLabel.text = [NSString stringWithFormat:@"输入的是%@",textField.text];
    if(textField.text.length <= 0){
        return YES;
    }
    NSMutableString * str = [[NSMutableString alloc] initWithString:textField.text];
    for(int i = 0; i < str.length;i++){
        NSString * oneS = [str substringWithRange:NSMakeRange(i, 1)];
        if([self validateWithRegExp:@"^\\d{1}$" withStr:oneS])continue;
        if([self validateWithRegExp:@"^[-，。！+*、=；：“”？@（）、/_""]{1}$" withStr:oneS])continue;
        unichar a = [str characterAtIndex:i];
        if(GetLanguageCode(a)){

        }else{
            [str replaceCharactersInRange:NSMakeRange(i, 1) withString:@" "];
        }
    }
    NSArray * array = [str componentsSeparatedByString:@" "];
    self.tipLabel.text = [array componentsJoinedByString:@""];
    
    
    return YES;
}

- (BOOL)validateWithRegExp: (NSString *)regExp withStr:(NSString *)text

{
    
    NSPredicate * predicate = [NSPredicate predicateWithFormat: @"SELF MATCHES %@", regExp];
    return [predicate evaluateWithObject:text];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
