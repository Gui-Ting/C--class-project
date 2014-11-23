object Form1: TForm1
  Left = 192
  Top = 127
  Width = 387
  Height = 246
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TrackBar1: TTrackBar
    Left = 24
    Top = 24
    Width = 209
    Height = 45
    Max = 255
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 0
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object Edit1: TEdit
    Left = 272
    Top = 24
    Width = 57
    Height = 33
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 80
    Top = 112
    Width = 75
    Height = 41
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 112
    Width = 75
    Height = 41
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Button2Click
  end
end
