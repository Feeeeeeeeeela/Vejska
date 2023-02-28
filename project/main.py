import wx
import wx.adv
import yt_ddl
from pathlib import Path
import string
import os
from subprocess import run

downloads_path = str(Path.home() / "Downloads")

class MyFrame(wx.Frame):
    def __init__(self, parent, title, size):
        super().__init__(parent, title =title, size = size)
        self.panel = MyPanel(self)
        self.SetSizeHints(550,300,550,300)
 
class MyPanel(wx.Panel):
    def __init__(self, parent):
        super().__init__(parent)
        self.GUI()

    def GUI(self): 
        mainsizer = wx.BoxSizer(wx.VERTICAL)

        sizer1 = wx.BoxSizer(wx.VERTICAL)
        self.url_ctrl = wx.TextCtrl(self,value="", style=wx.TE_LEFT,size=(400,22.5))
        sizer1.Add(wx.StaticText(self, label="URL:"), 0,wx.ALL | wx.EXPAND, 5)
        sizer1.Add(self.url_ctrl,0,wx.ALL|wx.EXPAND,5)

        sizer2 = wx.BoxSizer(wx.VERTICAL)
        self.name_ctrl = wx.TextCtrl(self,value="",style=wx.TE_LEFT)
        sizer2.Add(wx.StaticText(self, label="Name:"), 0,wx.ALL | wx.EXPAND, 5)
        sizer2.Add(self.name_ctrl,0,wx.ALL|wx.EXPAND,5)

        sizer3 = wx.BoxSizer(wx.HORIZONTAL)
        sizer3.Add(sizer1)
        sizer3.Add(sizer2)
        mainsizer.Add(sizer3)


        self.directory = wx.DirPickerCtrl(self, path=downloads_path)
        mainsizer.Add(wx.StaticText(self, label="Directory:"), 0,wx.ALL | wx.EXPAND, 5)
        mainsizer.Add(self.directory, 0, wx.ALL | wx.EXPAND, 5)

        sidesizer = wx.BoxSizer(wx.HORIZONTAL)

        self.datepicker = wx.adv.DatePickerCtrl(self, size=(120, -1), style=wx.adv.DP_DROPDOWN)
        self.hours_ctrl = wx.SpinCtrl(self, value="8", min=0, max=23)
        self.minutes_ctrl = wx.SpinCtrl(self, min=0, max=59)
        self.duration_ctrl = wx.SpinCtrl(self, value ="120",min=1, max=180)
        sidesizer.Add(wx.StaticText(self, label="Date:"), wx.ALL, 5)
        sidesizer.Add(self.datepicker, 0, wx.ALL| wx.EXPAND, 5)
        sidesizer.Add(wx.StaticText(self, label="Start: (HH:MM)"), wx.ALL,5)
        sidesizer.Add(self.hours_ctrl, 0, wx.ALL, 5)
        sidesizer.Add(self.minutes_ctrl, 0, wx.ALL, 5)
        sidesizer.Add(wx.StaticText(self, label="Duration: (min)"), wx.ALL,5)
        sidesizer.Add(self.duration_ctrl, 0, wx.ALL, 5)
        mainsizer.Add(sidesizer)


        self.download = wx.Button(self, label='Download')
        mainsizer.Add(self.download, 1, wx.ALL | wx.EXPAND, 5)

        self.SetSizer(mainsizer)
        self.download.Bind(wx.EVT_BUTTON, self.maindownload)
        
    def maindownload(self,event):
        date = self.datepicker.GetValue()
        date = date.FormatISODate()
        hours = self.hours_ctrl.GetValue()
        minutes = self.minutes_ctrl.GetValue()
        dur = self.duration_ctrl.GetValue()
        name = self.name_ctrl.GetValue()
        if hours < 10:
            hours="0"+str(hours)
        if minutes < 10:
            minutes="0"+str(minutes)
        url = str(self.url_ctrl.GetValue())
        time=date+"T"+str(hours)+":"+str(minutes)
        dur=str(dur)+"m"
        name=name+".mp4"
        args = [url,'--output',name,'--start',time,'--duration',dur]
        run(['python','yt_ddl.py'] + args)
        
 
class MyApp(wx.App):
    def OnInit(self):
        self.frame = MyFrame(parent=None, title="Livestream downloader", size = (400,300))
        self.frame.Show()
        return True
 
if __name__ == "__main__": 
    app=MyApp()
    app.MainLoop()
