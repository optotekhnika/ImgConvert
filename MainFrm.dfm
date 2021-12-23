object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1086#1085#1074#1077#1088#1090#1072#1094#1080#1103' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
  ClientHeight = 676
  ClientWidth = 681
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Radio: TRadioGroup
    Left = 0
    Top = 0
    Width = 321
    Height = 168
    Align = alLeft
    Caption = #1058#1080#1087' '#1087#1077#1088#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103
    Enabled = False
    Items.Strings = (
      'Red'
      'Green'
      'Blue'
      #1057#1088#1077#1076#1085#1077#1077' RGB'
      #1057#1091#1084#1084#1072' RGB')
    TabOrder = 0
    OnClick = RadioClick
    ExplicitHeight = 193
  end
  object GroupBox1: TGroupBox
    Left = 327
    Top = 0
    Width = 354
    Height = 168
    Align = alRight
    Caption = ' '
    TabOrder = 1
    ExplicitTop = 16
    ExplicitHeight = 152
    object ButtonLoad: TButton
      Left = 64
      Top = 24
      Width = 225
      Height = 34
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '
      TabOrder = 0
      OnClick = ButtonLoadClick
    end
    object ButtonSave: TButton
      Left = 64
      Top = 64
      Width = 225
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 1
      OnClick = ButtonSaveClick
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 168
    Width = 681
    Height = 508
    ActivePage = TabSheet1
    Align = alBottom
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #1054#1088#1080#1075#1080#1085#1072#1083
      ExplicitWidth = 520
      ExplicitHeight = 406
      object ImageSrc: TImage
        Left = 0
        Top = 0
        Width = 673
        Height = 480
        Hint = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077'-'#1086#1088#1080#1075#1080#1085#1072#1083
        Align = alClient
        ParentShowHint = False
        Proportional = True
        ShowHint = True
        Stretch = True
        ExplicitWidth = 525
        ExplicitHeight = 403
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103
      ImageIndex = 1
      ExplicitWidth = 520
      ExplicitHeight = 406
      object ImageDest: TImage
        Left = 0
        Top = 0
        Width = 673
        Height = 480
        Hint = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077'-'#1088#1077#1079#1091#1083#1100#1090#1072#1090
        Align = alClient
        ParentShowHint = False
        Proportional = True
        ShowHint = True
        Stretch = True
        ExplicitWidth = 525
        ExplicitHeight = 403
      end
    end
  end
  object Open: TOpenDialog
    DefaultExt = 'bmp'
    Filter = 'BMP images|*.bmp|JPEG images|*.jpg'
    FilterIndex = 0
    Options = [ofEnableSizing]
    Left = 287
    Top = 13
  end
  object Save: TSaveDialog
    Filter = 'Bitmap|*.bmp'
    Left = 327
    Top = 13
  end
end
