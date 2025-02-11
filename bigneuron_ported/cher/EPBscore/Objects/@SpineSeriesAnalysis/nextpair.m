function objseries=nextpair(objseries)
global self;
global objects;
global ogh;
global imageobj;
filenames=objseries.state.display.filenames;
pathname=objseries.state.pathname;
pathnames=objseries.state.display.pathnames;
fileselection=objseries.state.display.fileselection;
% Save previous images
try
    if (objseries.state.firstimage)
        global objects;
        str=getappdata(objseries.state.firstimage,'object');
        index=getappdata(objseries.state.firstimage,'index');
        imageobj=eval(str);
        imageobj=savebyname(imageobj,[],'');
        self=struct(imageobj);
        try
            path=self.state.Path;
            name=self.state.Name;
            
            pathnames(index)=cellstr([path '\' name '.spi']);
            objseries.state.display.pathnames=pathnames;
            set(objseries.gh.mainGUI.listbox,'String',objseries.state.display.pathnames);
            self=[];
        catch
        end
        destroy(imageobj);       
    end
catch
    disp(lasterr);
end
try
    if (objseries.state.secondimage)
        global objects;
        str=getappdata(objseries.state.secondimage,'object');
        index=getappdata(objseries.state.secondimage,'index');
        imageobj=eval(str);
        imageobj=savebyname(imageobj,[],'');
        try
            self=struct(imageobj);
            %path=self.state.rawImagePath;
            %name=self.state.rawImageName;
            path=self.state.Path;
            name=self.state.Name;
            
            pathnames(index)=cellstr([path '\' name '.spi']);
            objseries.state.display.pathnames=pathnames;
            set(objseries.gh.mainGUI.listbox,'String',objseries.state.display.pathnames);
            self=[];
        catch
        end
        destroy(imageobj);
    end
catch
    disp(lasterr);
end
try
    imageobj=[];
    self=[];
    ogh=[];
    if (fileselection<=size(filenames,2))
        filepath=char(pathnames(fileselection));
        [path,name,ext] = fileparts(filepath);
        objseries.state.firstimage=spineanalysisimageGUI;
        setappdata(objseries.state.firstimage,'index',fileselection);
        str=getappdata(objseries.state.firstimage,'object');
        imageobj=eval(str);
        if strcmp(ext,'.tif')
            imageobj=openImageByNameGUI(imageobj,filepath);
        elseif strcmp(ext,'.spi')
            imageobj=loadImageByNameGUI(imageobj,filepath);
        end
        set(0,'Units','Pixels')
        screensize=get(0,'ScreenSize');
        x=screensize(3);
        y=screensize(4);
        imageobj=set(imageobj,'state.display.windowpos',struct('mainGUI',[0.005*x 0.03*y 0.35*x 0.14*y],'profileGUI',[0.005*x 0.22*y 0.35*x 0.19*y],'projectionGUI',[0.005*x 0.44*y 0.495*x 0.53*y],'imageGUI',[0.005*x 0.44*y 0.495*x 0.53*y]));
        imageobj=initializeconditions(imageobj);
        self=struct(imageobj);
        ogh=self.gh;        
        try
            displayProjectionImage(imageobj);
            displayProfile(imageobj);
        catch
            disp(lasterr);
        end
        eval([str '=imageobj;']);
    end
    imageobj=[];
    self=[];
    ogh=[];
    if (fileselection+1<=size(filenames,2))
        filepath=char(pathnames(fileselection+1));
        [path,name,ext] = fileparts(filepath);
        objseries.state.secondimage=spineanalysisimageGUI;
        setappdata(objseries.state.secondimage,'index',fileselection+1);
        str=getappdata(objseries.state.secondimage,'object');
        imageobj=eval(str);
        if strcmp(ext,'.tif')
            imageobj=openImageByNameGUI(imageobj,filepath);
        elseif strcmp(ext,'.spi')
            imageobj=loadImageByNameGUI(imageobj,filepath);
        end
        set(0,'Units','Pixels')
        screensize=get(0,'ScreenSize');
        x=screensize(3);
        y=screensize(4);
        imageobj=set(imageobj,'state.display.windowpos',struct('mainGUI',[0.36*x 0.03*y 0.35*x 0.14*y],'profileGUI',[0.36*x 0.22*y 0.35*x 0.19*y],'projectionGUI',[0.505*x 0.44*y 0.495*x 0.53*y],'imageGUI',[0.005*x 0.44*y 0.495*x 0.53*y]));
        imageobj=initializeconditions(imageobj);  
        self=struct(imageobj);
        ogh=self.gh;        
        try
            displayProjectionImage(imageobj);
            displayProfile(imageobj);
        catch
            disp(lasterr);
        end
        eval([str '=imageobj;']);
    end
catch
    disp(lasterr);
end
function imageobj=initializeconditions(imageobj)
        global self
        imageobj=set(imageobj,'state.display.displayfiltered',0);
        imageobj=set(imageobj,'state.display.displayraw',1);
        imageobj=set(imageobj,'state.display.displaybinary',0);        
        imageobj=set(imageobj,'state.display.showprofile',1);
        imageobj=set(imageobj,'state.display.showprojection',1);
        imageobj=set(imageobj,'state.display.showparameters',0);
        imageobj=set(imageobj,'state.display.showstack',0);
        imageobj=updateWindowPosByObj(imageobj);
        imageobj=showprojection(imageobj);
        imageobj=showprofile(imageobj);
        imageobj=set(imageobj,'state.display.ch1',1);
        imageobj=set(imageobj,'state.display.ch2',0);
        imageobj=set(imageobj,'state.display.lowpixelch1',0);
        imageobj=set(imageobj,'state.display.highpixelch1',300);
        imageobj=set(imageobj,'state.display.lowpixelch1',0);
        imageobj=set(imageobj,'state.display.binarythreshold',30);
        imageobj=set(imageobj,'state.display.displayMA',0);
        imageobj=set(imageobj,'state.display.displaydendrites',1);
        imageobj=set(imageobj,'state.display.displayspines',1);
        imageobj=set(imageobj,'state.display.displaymarks',1);
        imageobj=set(imageobj,'state.display.axonnumber',1);
        imageobj=set(imageobj,'state.GUI',1);
        imageobj=set(imageobj,'state.display.keepintermediates',1);
        imageobj=set(imageobj,'state.display.currentz',1);
        self=struct(imageobj);
        updateGUIbyglobal('self.state.display.displayfiltered');
        updateGUIbyglobal('self.state.display.displayraw');
        updateGUIbyglobal('self.state.display.displaybinary');
        updateGUIbyglobal('self.state.display.ch1');
        updateGUIbyglobal('self.state.display.lowpixelch1');
        updateGUIbyglobal('self.state.display.highpixelch1');
        updateGUIbyglobal('self.state.display.axonnumber');
        updateGUIbyglobal('self.state.display.displaydendrites');
        updateGUIbyglobal('self.state.display.displayspines');
        updateGUIbyglobal('self.state.display.displaymarks');
        updateGUIbyglobal('self.state.display.currentz');
        updateGUIbyglobal('self.state.display.binarythreshold');

        
