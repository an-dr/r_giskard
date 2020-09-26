#!/usr/bin/env python
# encoding: utf-8

import npyscreen


class simTUI(npyscreen.Form):
    def activate(self):
        self.edit()

    def create(self):
        self.s1 = self.add(npyscreen.TitleSlider, out_of=100, name="Light")
        self.s2 = self.add(npyscreen.TitleSlider, out_of=100, name="Proximity")
        self.t1 = self.add(npyscreen.FixedText, name="Text", value="Vals")
        self.t2 = self.add(npyscreen.FixedText, name="Text", value="Vals")

    def adjust_widgets(self, *args, **keywords):
        self.t1.value = str(self.s1.value) + " t1"
        self.t2.value = str(self.s2.value) + " t2"


class TestApp(npyscreen.NPSApp):
    def main(self):
        F = simTUI(name="RG_SIMULATOR")
        F.edit()


if __name__ == "__main__":
    App = TestApp()
    App.run()
