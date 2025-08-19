% PDFREAD Demo
% D. Wood, 7/3/2017
%

% add the java path for the iText java library.
javaaddpath('iText-4.2.0-com.itextpdf.jar')

% read the PDF file.
pdf_text = pdfRead('FREELANCE_PROJECT.pdf');

pdf_text = cellfun(@(x) string(splitlines(x)), pdf_text, 'UniformOutput', false);
totalCount = 0;
for pageCnt = 7:length(pdf_text)
    totalCount = totalCount + length(pdf_text{pageCnt});
end
opStrArrayPage = string(char(zeros(length(totalCount), 0)));
cnt = 1649;

for pageCnt = 7:length(pdf_text)
    page = pdf_text{pageCnt};
    page(contains(page, 'Oxford')) = [];
    page(startsWith(page, ' ')) = [];
    page(cell2mat(isstrprop(extractBefore(page, 2), 'digit'))) = [];
    [opStrArrayPage, cnt] = getReqPage(opStrArrayPage, page, cnt);
    disp(['done with page number ' num2str(pageCnt)])
end
xlswrite('allWordsPage7plus.xlsx', opStrArrayPage);
msgbox('done');
